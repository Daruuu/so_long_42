#!/bin/bash

# Definir colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Verifica si el directorio de mapas fue proporcionado como argumento
if [ -z "$1" ]; then
  echo -e "${RED}Uso: $0 <directorio_de_mapas>${NC}"
  exit 1
fi

# Recorre cada archivo que tenga un nombre con algo antes del punto en el directorio proporcionado
for map in "$1"/*.*; do
  # Verifica si el nombre del archivo tiene algo antes del punto
  filename=$(basename -- "$map")
  if [[ "$filename" =~ ^[^.]+\..* ]]; then
    echo -e "${YELLOW}Ejecutando ./so_long con el archivo $map${NC}"
    ./so_long "$map"

    # Captura el código de salida de ./so_long
    result=$?

    # Muestra un mensaje según el resultado del comando
    if [ $result -eq 0 ]; then
      echo -e "${GREEN}ARCHIVO $map EJECUTADO CORRECTAMENTEEEE!!1.${NC}"
    else
      echo -e "${RED}Error al ejecutar el ARCHIVO: $map.${NC}"
      echo -e "${RED}Código de salida: $result${NC}"
    fi
  fi
done
