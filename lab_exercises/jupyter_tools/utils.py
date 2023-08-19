from IPython.display import display, Markdown

def display_matrix(name, matrix, display_md=True, print_py=False, digits=2):
    if matrix.ndim == 1:
        matrix = matrix.reshape(-1, 1)  # Reshape 1D array as a column vector
    rows, cols = matrix.shape
    matrix_str = "\\begin{bmatrix}"
    for i in range(rows):
        row_str = " & ".join([f"{matrix[i, j]:.{digits}f}" for j in range(cols)])
        matrix_str += f"{row_str} \\\\\n"
    matrix_str = matrix_str.rstrip(" \\\\\n")  # Remove trailing line break for single-row/column matrix
    matrix_str += "\\end{bmatrix}"
    matrix_str = f"${name} = {matrix_str}$"
    
    if print_py == True:
        print(matrix_str)
    if display_md == True:
        display(Markdown(matrix_str))

def display_congratulations():
    message = "**<span style='color:green'>Congratulations on your successful implementation!!</span>**"
    display(Markdown(message))

def display_error(custom_message=None):
    error_message = "**<span style='color:red'>Error: Something went wrong. Please try again.</span>**"
    if custom_message:
        error_message += f"\n\n<span style='color:red'>Check your implementation of {custom_message}</span>"
    display(Markdown(error_message))