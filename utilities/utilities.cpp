#include "utilities.h"

//
// Utility stuff implementation
//

namespace frupal_utils{
  using namespace std;

  //
  // Universal position structure
  //

  Position::Position() : x(0), y(0){}
  Position::Position(const int x, const int y) : x(x), y(y){}
  Position::Position(const Position& source){ this->x = source.x; this->y = source.y; }

  Position Position::operator + (const Position & src){ return Position(this->x + src.x, this->y + src.y); }
  Position Position::operator - (const Position & src){ return Position(this->x - src.x, this->y - src.y); }

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
    cerr << "[ERROR]: No textures were found for the " << obj_type << " object!" << endl;
  }

  TextureMap::TextureMap(const char* filename) : size(0){
    ifstream file;
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
