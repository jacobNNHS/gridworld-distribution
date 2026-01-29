/**
 * GridWorld
 * 
 * A grid-based world simulation where entities can be placed, moved, and queried.
 * This program uses 2D arrays and structs to manage a simple virtual world.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GRID_SIZE 10
#define MAX_ENTITIES 100

// Entity structure to track objects in the world
typedef struct
{
    char type;      // 'P' (person), 'T' (tree), 'R' (rock), 'W' (water)
    int row;
    int col;
    bool active;    // whether this entity is still in the world
}
Entity;

// Function prototypes
void init_grid(char grid[GRID_SIZE][GRID_SIZE]);
void display_grid(char grid[GRID_SIZE][GRID_SIZE]);
bool place_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int *entity_count, char type, int row, int col);
bool move_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int entity_count, int from_row, int from_col, const char *direction);
int count_neighbors(char grid[GRID_SIZE][GRID_SIZE], int row, int col, char type);
void remove_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int row, int col);
void list_entities(Entity entities[], int entity_count);
void print_help(void);

int main(void)
{
    // Initialize the grid and entity array
    char grid[GRID_SIZE][GRID_SIZE];
    Entity entities[MAX_ENTITIES];
    int entity_count = 0;
    
    init_grid(grid);
    
    printf("Welcome to GridWorld!\n");
    printf("Type 'help' for a list of commands.\n\n");
    
    // Main command loop
    char command[100];
    while (true)
    {
        printf("Enter command: ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }
        
        // Remove newline
        command[strcspn(command, "\n")] = 0;
        
        // Parse command
        char cmd[20], arg1[20], arg2[20], arg3[20];
        int args = sscanf(command, "%s %s %s %s", cmd, arg1, arg2, arg3);
        
        if (args < 1)
        {
            continue;
        }
        
        // Handle commands
        if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if (strcmp(cmd, "help") == 0)
        {
            print_help();
        }
        else if (strcmp(cmd, "display") == 0)
        {
            display_grid(grid);
        }
        else if (strcmp(cmd, "list") == 0)
        {
            list_entities(entities, entity_count);
        }
        else if (strcmp(cmd, "place") == 0)
        {
            if (args != 4)
            {
                printf("Usage: place <type> <row> <col>\n");
                continue;
            }
            
            char type = arg1[0];
            int row = atoi(arg2);
            int col = atoi(arg3);
            
            if (place_entity(grid, entities, &entity_count, type, row, col))
            {
                printf("Placed %c at (%d, %d)\n", type, row, col);
            }
            else
            {
                printf("Could not place entity at (%d, %d)\n", row, col);
            }
        }
        else if (strcmp(cmd, "move") == 0)
        {
            if (args != 4)
            {
                printf("Usage: move <row> <col> <direction>\n");
                continue;
            }
            
            int row = atoi(arg1);
            int col = atoi(arg2);
            
            if (move_entity(grid, entities, entity_count, row, col, arg3))
            {
                printf("Moved entity from (%d, %d)\n", row, col);
            }
            else
            {
                printf("Could not move entity from (%d, %d)\n", row, col);
            }
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            if (args != 3)
            {
                printf("Usage: remove <row> <col>\n");
                continue;
            }
            
            int row = atoi(arg1);
            int col = atoi(arg2);
            remove_entity(grid, entities, row, col);
            printf("Removed entity at (%d, %d)\n", row, col);
        }
        else if (strcmp(cmd, "neighbors") == 0)
        {
            if (args != 4)
            {
                printf("Usage: neighbors <row> <col> <type>\n");
                continue;
            }
            
            int row = atoi(arg1);
            int col = atoi(arg2);
            char type = arg3[0];
            
            int count = count_neighbors(grid, row, col, type);
            printf("Found %d neighbor(s) of type %c near (%d, %d)\n", count, type, row, col);
        }
        else
        {
            printf("Unknown command. Type 'help' for options.\n");
        }
    }
    
    return 0;
}

/**
 * Initialize the grid with empty spaces
 */
void init_grid(char grid[GRID_SIZE][GRID_SIZE])
{
    // TODO: Implement this function
    (void)grid;  // Remove this line when you implement the function
}

/**
 * Display the current state of the grid
 */
void display_grid(char grid[GRID_SIZE][GRID_SIZE])
{
    // TODO: Implement this function
    (void)grid;  // Remove this line when you implement the function
}

/**
 * Place an entity on the grid
 * Returns true if successful, false otherwise
 */
bool place_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int *entity_count, char type, int row, int col)
{
    // TODO: Implement this function
    (void)grid;          // Remove these lines when you implement the function
    (void)entities;
    (void)entity_count;
    (void)type;
    (void)row;
    (void)col;
    
    return false;
}

/**
 * Move an entity in the specified direction
 * Returns true if successful, false otherwise
 */
bool move_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int entity_count, int from_row, int from_col, const char *direction)
{
    // TODO: Implement this function
    (void)grid;          // Remove these lines when you implement the function
    (void)entities;
    (void)entity_count;
    (void)from_row;
    (void)from_col;
    (void)direction;
    
    return false;
}

/**
 * Count neighbors of a specific type around a position
 * Includes all 8 adjacent cells (including diagonals)
 */
int count_neighbors(char grid[GRID_SIZE][GRID_SIZE], int row, int col, char type)
{
    // TODO: Implement this function
    (void)grid;  // Remove these lines when you implement the function
    (void)row;
    (void)col;
    (void)type;
    
    return 0;
}

/**
 * Remove an entity from the grid
 */
void remove_entity(char grid[GRID_SIZE][GRID_SIZE], Entity entities[], int row, int col)
{
    // TODO: Implement this function
    (void)grid;      // Remove these lines when you implement the function
    (void)entities;
    (void)row;
    (void)col;
}

/**
 * List all active entities
 */
void list_entities(Entity entities[], int entity_count)
{
    // TODO: Implement this function
    (void)entities;      // Remove these lines when you implement the function
    (void)entity_count;
}

/**
 * Print help information
 */
void print_help(void)
{
    printf("\nAvailable commands:\n");
    printf("  place <type> <row> <col>  - Place an entity (P=person, T=tree, R=rock, W=water)\n");
    printf("  move <row> <col> <dir>    - Move entity (dir: up, down, left, right)\n");
    printf("  display                   - Show the grid\n");
    printf("  list                      - List all entities\n");
    printf("  neighbors <row> <col> <type> - Count neighbors of a type\n");
    printf("  remove <row> <col>        - Remove an entity\n");
    printf("  help                      - Show this help\n");
    printf("  quit                      - Exit program\n\n");
}
