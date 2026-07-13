# Nom de l'application
TARGET = exemple

# Répertoires
SRC_DIR = ./src
BUILD_DIR = ./build

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -O2 -I$(SRC_DIR) -MMD -MP

# Sources C
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Fichiers de dépendances générés (.d)
DEPS = $(OBJECTS:.o=.d)

# Cible par défaut
all: $(TARGET)

# Édition des liens
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Compilation des sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Inclusion des dépendances générées automatiquement
-include $(DEPS)

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Reconstruction complète
rebuild: clean all

.PHONY: all clean rebuild