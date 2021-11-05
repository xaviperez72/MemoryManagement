#include "graphedge.h"
#include "graphnode.h"

// forward declarations
class ChatLogic;

GraphNode::GraphNode(int id)
{
    _id = id;
    counter++;
    Print("GraphNode Constructor " << counter);
}

GraphNode::~GraphNode()
{
    Print("GraphNode Destructor " << counter);
    counter--;
    //// STUDENT CODE
    ////

    // TASK 0 - AVOID CORE DUMP - XAVI PEREZ
    // 
    // if (_chatBot != nullptr)
    //    delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)         // task 4 
{
    // https://knowledge.udacity.com/questions/144954
    _childEdges.push_back(std::move(edge));         // TASK 4 
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)                // TASK 5 - BY VALUE
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);

    // ChatLogic *p;    
    // p = _chatBot.GetChatLogicHandle();
    // p->SetChatbotHandle(&_chatBot); // HARD TO FIND IT. 
    //    this->_chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);     They are not friends!!  
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    //  _chatBot = nullptr; // invalidate pointer at source         TASK 5 
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}