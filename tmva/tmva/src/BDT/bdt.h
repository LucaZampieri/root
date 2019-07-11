#include <string>
#include <map>


// Test class

class AbstractNode{ // TODO make it abstract with pure virtual method
private:
  // double threshold = 0; --> moved to public

protected:
public:
  std::string kind; 
  double threshold = 0;
  std::string split_variable;
  int node_id;
  int depth;
  int missing; // what is missing

  //float get_threshold(){this->threshold;}

  //virtual std::string getKind();
};


class Node : public AbstractNode{
public:
  int child_id_true;
  int child_id_false;
  AbstractNode* child_true;
  AbstractNode* child_false;
  Node(){kind = "NormalNode";}
};

class LeafNode : public AbstractNode{
public:
  double leaf_true = 0;
  double leaf_false = 0;
  LeafNode(){kind = "LeafNode";}
};

//class tree
class Tree{
public:
  //std::map< unsigned int, std::map<unsigned int, AbstractNode> > nodes;
  std::vector<AbstractNode*> nodes;
  double inference(double event[]){
    return 0;
  }
};

// Definition of printname using scope resolution operator ::
/*int Node::get_child_num()
{
    return this->child_number;
}*/
