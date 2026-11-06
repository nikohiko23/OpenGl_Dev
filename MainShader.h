#ifndef MAINSHADER_H
#define MAINSHADER_H

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Shader
{
  public:
    // идентификатор программы
    unsigned int ID;

    // Конструктор считывает данные и выполняет построение шейдера
    Shader(const char *vertexPath, const char *fragmentPath);

    // Использование/активация шейдера
    void use();

    // Полезные uniform-функции
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

  private:
    void checkCompileErrors(unsigned int shader, const std::string &type);
};

#endif