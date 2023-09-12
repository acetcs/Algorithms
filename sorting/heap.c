#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Data structure for a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* newNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to construct a binary tree from an array
TreeNode* constructTree(int array[], int index, int size) {
    if (index < size) {
        TreeNode* root = newNode(array[index]);
        root->left = constructTree(array, 2 * index + 1, size);
        root->right = constructTree(array, 2 * index + 2, size);
        return root;
    }
    return NULL;
}

// Function to draw a binary tree
void drawTree(SDL_Renderer* renderer, TreeNode* root, int x, int y, int level) {
    if (root == NULL)
        return;

    // Draw the current node
    SDL_Rect rect = { x, y, 40, 40 };
    SDL_RenderDrawRect(renderer, &rect);
    char text[10];
    snprintf(text, sizeof(text), "%d", root->data);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &rect);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);

    // Calculate the coordinates for child nodes
    int xOffset = SCREEN_WIDTH / (1 << level);
    int yOffset = 60;

    // Draw left child and the connecting line
    drawTree(renderer, root->left, x - xOffset, y + yOffset, level + 1);
    SDL_RenderDrawLine(renderer, x + 20, y + 40, x - xOffset + 20, y + yOffset);

    // Draw right child and the connecting line
    drawTree(renderer, root->right, x + xOffset, y + yOffset, level + 1);
    SDL_RenderDrawLine(renderer, x + 20, y + 40, x + xOffset + 20, y + yOffset);
}

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer
    window = SDL_CreateWindow("Binary Tree Representation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Sample array representing the binary tree
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Construct the binary tree from the array
    TreeNode* root = constructTree(array, 0, sizeof(array) / sizeof(array[0]));

    // Main loop
    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw the binary tree
        drawTree(renderer, root, SCREEN_WIDTH / 2, 50, 1);

        // Update the renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
