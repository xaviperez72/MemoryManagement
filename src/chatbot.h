#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include "common.h"

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE                   TASK 2 - RULE OF FIVE
    ////
    ChatBot(const ChatBot &r);              // Copy Constructor
    ChatBot& operator=(const ChatBot &r);    // Assignment operator
    ChatBot(ChatBot &&r);                   // Move Constructor
    ChatBot& operator=(ChatBot &&r);         // Move Assignment operator
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { 
        Print("ChatBot::SetChatLogicHandle _chatLogic = chatLogic;");
        _chatLogic = chatLogic; 
    }
    ChatLogic* GetChatLogicHandle() { 
        Print("ChatBot::GetChatLogicHandle return _chatLogic");
        return _chatLogic; 
    }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);

};

#endif /* CHATBOT_H_ */
