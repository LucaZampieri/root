#include "unique_bdt.h"
#include <string>
#include <map>
#include <iostream>

namespace unique_bdt {

// counter
int Node::count = 0;

// Reading members of the json
void write_node_members(json const &jTree, std::unique_ptr<Node> &tmp_node)
{
   tmp_node->split_threshold = jTree.at("split_condition");
   std::string tmp_str       = jTree.at("split").get<std::string>();
   tmp_str.erase(tmp_str.begin(), tmp_str.begin() + 1); // remove initial "f"
   tmp_node->split_variable = std::stoi(tmp_str);
}

// /*
std::unique_ptr<Node> _read_nodes(json const &jTree, Tree &tree)
{
   std::unique_ptr<Node> tmp_node(new Node);
   write_node_members(jTree, tmp_node);
   if (jTree.at("children").at(0).find("leaf") != jTree.at("children").at(0).end()) {
      tmp_node->leaf_true    = jTree.at("children").at(0).at("leaf");
      tmp_node->is_leaf_node = 1;
   } else {
      tmp_node->child_true = _read_nodes(jTree.at("children").at(0), tree);
   }
   if (jTree.at("children").at(1).find("leaf") != jTree.at("children").at(1).end()) {
      tmp_node->leaf_false   = jTree.at("children").at(1).at("leaf");
      tmp_node->is_leaf_node = 1;
   } else {
      tmp_node->child_false = _read_nodes(jTree.at("children").at(1), tree);
   }
   return std::move(tmp_node);
}
// */

/// read tree structure from xgboost json file
void read_nodes_from_tree(json const &jTree, Tree &tree)
{
   tree.nodes = _read_nodes(jTree, tree);
}

} // namespace unique_bdt

// end file
