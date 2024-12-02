// JavaScript source code
var Module = {
            onRuntimeInitialized: () => {
                const form = document.getElementById("imc-form");
                const output = document.getElementById("output");
                const patients = document.getElementById("patients");

                form.addEventListener("submit", function (e) {
                    e.preventDefault();

                    const poids = parseFloat(document.getElementById("poids").value);
                    const taille = parseFloat(document.getElementById("taille").value);

                    // Appeler la fonction C pour calculer l'IMC
                    const resultat = Module.ccall(
                        'traiter_patient', // Nom de la fonction C
                        'string',          // Type de retour
                        ['number', 'number'], // Types des param�tres
                        [poids, taille]    // Valeurs des param�tres
                    );

                    // Afficher le r�sultat
                    output.innerText = resultat;

                    // Obtenir le nombre total de patients trait�s
                    const totalPatients = Module.ccall(
                        'obtenir_nombre_patients', // Nom de la fonction
                        'number',                  // Type de retour
                        [],                        // Pas de param�tres
                        []
                    );
                    patients.innerText = `Nombre total de patients trait�s : ${totalPatients}`;
                });
            }
        };