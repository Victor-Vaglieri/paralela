import subprocess

def get_last_terminal_output():
    # Executa um comando no terminal e captura o último output
    result = subprocess.run(['tail', '-n', '1', 'output.log'], capture_output=True, text=True)
    return result.stdout.strip()

def read_file_content(file_path):
    with open(file_path, 'r') as file:
        return file.read().strip()

def count_matching_characters(str1, str2):
    # Contar o número de caracteres iguais nas posições correspondentes
    min_length = min(len(str1), len(str2))
    return sum(1 for i in range(min_length) if str1[i] == str2[i])

def main():
    # Supondo que o último output do terminal esteja salvo em 'output.log'
    terminal_output = get_last_terminal_output()
    file_content = read_file_content('comparar.txt')
    
    matching_characters = count_matching_characters(terminal_output, file_content)
    
    print(f"Número de caracteres iguais: {matching_characters}")

if __name__ == "__main__":
    main()
