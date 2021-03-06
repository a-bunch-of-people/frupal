#include "utilities.h"

//
// Utility stuff implementation
//

namespace frupal_utils{
  //
  // Universal position structure
  //

  Position::Position() : x(0), y(0){}
  Position::Position(const int x, const int y) : x(x), y(y){}
  Position::Position(const Position& source){ this->x = source.x; this->y = source.y; }

  Position Position::operator + (const Position & src){ return Position(this->x + src.x, this->y + src.y); }
  Position Position::operator - (const Position & src){ return Position(this->x - src.x, this->y - src.y); }

  const double operator% (const Position& p1, const Position& p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
  }

  std::ostream& operator<< (std::ostream & buffer, const Position& source){
    buffer << "(" << source.x << "," << source.y << ")";
    return buffer;
  }

  //
  // Error Typdefs
  //

  NULL_TEXTURE::NULL_TEXTURE(const char* obj_type){
    this->obj_type = new char[strlen(obj_type) + 1];
    strcpy(this->obj_type, obj_type);
  }

  NULL_TEXTURE::~NULL_TEXTURE(){
    delete [] obj_type;
  }

  void NULL_TEXTURE::what(){
    std::cerr << "[ERROR]: No textures were found for the " << obj_type << " object!" << std::endl;
  }

  POSITION_OUT_OF_BOUNDS::POSITION_OUT_OF_BOUNDS(const Position& bad_position) : bad_position(bad_position){}

  POSITION_OUT_OF_BOUNDS::~POSITION_OUT_OF_BOUNDS(){}

  void POSITION_OUT_OF_BOUNDS::what(){
    std::cerr << "[ERROR]: Position was out of bounds: " << bad_position << std::endl;
  }

  //
  // Texture Map Implementation
  //

  TextureMap::TextureMap(const char* filename) : size(0){
    std::ifstream file;
    char* name = new char[MAX_STREAM_SIZE];
    char* list = new char[MAX_STREAM_SIZE];

    texture_name = new char*[MAX_STREAM_SIZE];
    texture_list = new char[MAX_STREAM_SIZE];

    file.open(filename);
    while(!file.eof()){
      file.get(name, MAX_STREAM_SIZE, ';');
      file.get();
      file.get(list, MAX_STREAM_SIZE, '\n');
      file.get();

      list[1] = '\0';

      if(strcmp(name,"") != 0){
        texture_name[size] = new char[strlen(name)];
        strcpy(texture_name[size], name);
        strcat(texture_name[size], "\0");
        strcat(texture_list, list);
        size++;
      }
    }
    file.close();

    delete [] name;
    delete [] list;
  }

  TextureMap::~TextureMap(){
    for(int i = 0; i < size; i++){
      if(texture_name[i])
        delete texture_name[i];
    }

    if(texture_name)
      delete [] texture_name;
    if(texture_list)
      delete [] texture_list;
  }

  std::ostream& operator<< (std::ostream& buffer, const TextureMap& source){
    buffer << "{ ";
    for(int i = 0; i < source.size; i++){
      buffer << source.texture_name[i] << ": \'" << source.texture_list[i] << "\'";

      if(i != (source.size - 1))
        buffer << ", ";
    }
    buffer << " }";
    return buffer;
  }

  void sleep(const int sleep_time){
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
  }
}
