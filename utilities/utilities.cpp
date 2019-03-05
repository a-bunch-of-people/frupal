#include "utilities.h"

//
// Utility stuff implementation
//

namespace frupal_utils {
  using namespace std;

  //
  // Error Typdefs
  //

  NULL_TEXTURE::NULL_TEXTURE(const char* obj_type) {
    this->obj_type = new char[strlen(obj_type) + 1];
    strcpy(this->obj_type, obj_type);
  }

  NULL_TEXTURE::~NULL_TEXTURE() {
    delete [] obj_type;
  }

  void NULL_TEXTURE::what() {
    cerr << "[ERROR]: No textures were found for the " << obj_type << " object!" << endl;
  }

  TextureMap::TextureMap() : size(0) {}

  TextureMap::~TextureMap() {
    for(int i = 0; i < size; ++i) {
      if(tile_types[i])
        delete tile_types[i];
    }

    delete [] tile_types;
    delete [] textures;
  }

  void TextureMap::display() {
    for(int i = 0; i < size; ++i) {
      if(tile_types[i] && tile_types[i][0] != '\0')
        cout << "TILE: \"" << tile_types[i] << "\" TEXTURE: \'" << textures[i] << "\'" << endl;
    }
  }

  void load_textures(TextureMap &textures, const char* filename) {
    int i = 0;
    char** tile_types = new char*[MAX_STREAM_SIZE];
    char* temp_textures = new char[MAX_STREAM_SIZE];

    ifstream file;
    char* type = new char[MAX_STREAM_SIZE];
    char* texture = new char[MAX_STREAM_SIZE];

    file.open(filename);

    while(!file.eof()) {
      file.get(type, MAX_STREAM_SIZE, ';');

      if(type[0] == '\0') // If type is emty, stop reading
        break;

      file.ignore(1);
      file.get(texture, MAX_STREAM_SIZE, '\n');
      file.ignore(1);

      tile_types[i] = new char[strlen(type) + 1];
      strcpy(tile_types[i], type);
      strcat(tile_types[i], "\0");
      temp_textures[i] = texture[0];

      ++i;
    }

    textures.size = i;
    textures.tile_types = new char*[i];
    textures.textures = new char[i];

    for(int j = 0; j < i; ++j) {
      textures.tile_types[j] = new char[strlen(tile_types[j]) + 1];
      strcpy(textures.tile_types[j], tile_types[j]);
      strcat(tile_types[i], "\0");
      textures.textures[j] = temp_textures[j];
    }

    if(DEBUG) {
      cout << "[INFO]: Loaded a total of " << i << " textures!" << endl;

      for(int j = 0; j < i; ++j) {
        cout << "\tMAPPED " << temp_textures[j] << " to " << tile_types[j] << endl;
      }
    }

    file.close();

    //
    // Destruction Phase
    //

    for(int j = 0; j < i; ++j) {
      if(tile_types[j] && tile_types[j][0] != '\0' )
        delete tile_types[j];
    }

    delete [] tile_types;
    delete [] temp_textures;
    delete [] type;
    delete [] texture;
  }

  void sleep(const int sleep_time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
  }
}
