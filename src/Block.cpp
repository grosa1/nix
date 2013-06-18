
#include <pandora/Block.hpp>

using namespace std;

namespace pandora {


/* SEE: SimpleTag.hpp */
Block::Block(const Block &block) :
    NamedEntity(block.file, block.group, block.entity_id)
{}

/* SEE: SimpleTag.hpp */
Block::Block(File *file, Group group, std::string id) :
    NamedEntity(file, group, id)
{}

Block::~Block() {
  //dtor
}

} // end namespace pandora
