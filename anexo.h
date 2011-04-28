/*
Ricardo Pinto Lopes 2008114843
Rui Pedro da Cunha Santos Chicória 2008115099
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Emerald
GLfloat emeraldAmbient[] = {0.0125, 0.1745, 0.0215};
GLfloat emeraldDiffuse[] = {0.07568, 0.61424, 0.07568};
GLfloat emeraldSpecular[] = {0.633, 0.727811, 0.633};
GLfloat emeraldShininess = 128 * 0.6;

// Jade
GLfloat jadeAmbient[] = {0.135, 0.2225, 0.1575};
GLfloat jadeDiffuse[] = {0.54, 0.89, 0.63};
GLfloat jadeSpecular[] = {0.316228, 0.316228, 0.316228};
GLfloat jadeShininess = 128 * 0.1;

// Obsidian
GLfloat obsidianAmbient[] = {0.05375, 0.05, 0.06625};
GLfloat obsidianDiffuse[] = {0.18275, 0.17, 0.22525};
GLfloat obsidianSpecular[] = {0.332741, 0.328634, 0.346435};
GLfloat obsidianShininess = 128 * 0.3;

// Pearl
GLfloat pearlAmbient[] = {0.25, 0.20725, 0.20725};
GLfloat pearlDiffuse[] = {1.0, 0.829, 0.829};
GLfloat pearlSpecular[] = {0.296648, 0.296648, 0.296648};
GLfloat pearlShininess = 128 * 0.088;

// Ruby
GLfloat rubyAmbient[] = {0.1745, 0.01175, 0.01175};
GLfloat rubyDiffuse[] = {0.61424, 0.04136, 0.04136};
GLfloat rubySpecular[] = {0.727811, 0.626959, 0.626959};
GLfloat rubyShininess = 128 * 0.6;

// Turquoise
GLfloat turquoiseAmbient[] = {0.1, 0.18725, 0.1745};
GLfloat turquoiseDiffuse[] = {0.396, 0.74151, 0.69102};
GLfloat turquoiseSpecular[] = {0.297254, 0.30829, 0.306678};
GLfloat turquoiseShininess = 128 * 0.1;
// Brass
GLfloat brassAmbient[] = {0.329412, 0.223529, 0.027451};
GLfloat brassDiffuse[] = {0.780392, 0.568627, 0.113725};
GLfloat brassSpecular[] = {0.992157, 0.941176, 0.807843};
GLfloat brassShininess = 128 * 0.21794872;

// Bronze
GLfloat bronzeAmbient[] = {0.2125, 0.1275, 0.054};
GLfloat bronzeDiffuse[] = {0.714, 0.4284, 0.18144};
GLfloat bronzeSpecular[] = {0.393548, 0.271906, 0.166721};
GLfloat bronzeShininess = 128 * 0.2;

// Black
GLfloat blackAmbient[] = {0.0, 0.0, 0.0};
GLfloat blackDiffuse[] = {0.0, 0.0, 0.0};
GLfloat blackSpecular[] = {0, 0, 0};
GLfloat blackShininess = 0;
