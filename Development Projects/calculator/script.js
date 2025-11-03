const output = document.querySelector(".output");
const buttons = document.querySelectorAll(".btn");

let currentInput = "";
let operator = "";
let previousInput = "";

// Show output
function updateOutput(value)
 {
    output.textContent = value;
}

// Add event listeners to buttons
buttons.forEach(button => {
    button.addEventListener("click", () =>
         {
        const value = button.id;

        if (!isNaN(value) || value === "decimal")
             {
            // Numbers and decimal
            if (value === "decimal" && currentInput.includes(".")) 
                return;
            currentInput += value === "decimal" ? "." : value;
            updateOutput(currentInput);

        } else if (button.classList.contains("operator") && value !== "equals")
             {
            // Operators (+ - * / %)
            if (currentInput === "" && previousInput === "") return;
            if (currentInput !== "")
                 {
                previousInput = currentInput;
                currentInput = "";
            }
            operator = value;
            updateOutput(operator);

        } else if (value === "equals")
             {
            // Equal sign
            if (previousInput && currentInput && operator)
                {
                let expression = previousInput + " " + operatorSymbol(operator) + " " + currentInput;
                let result = eval(expression);
                updateOutput(result);
                currentInput = result.toString();
                previousInput = "";
                operator = "";
            }

        } else if (value === "clear") 
            {
            // Clear
            currentInput = "";
            previousInput = "";
            operator = "";
            updateOutput("");

        } else if (value === "backspace") 
            {
            // Backspace
            currentInput = currentInput.slice(0, -1);
            updateOutput(currentInput);
        }
    });
});

// Helper function for operator symbols
function operatorSymbol(op) {
    switch (op) {
        case "add": return "+";
        case "subtract": return "-";
        case "multiply": return "*";
        case "divide": return "/";
        case "percent": return "%";
        default: return "";
    }
}
