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
                        ['number', 'number'], // Types des paramètres
                        [poids, taille]    // Valeurs des paramètres
                    );

                    // Afficher le résultat
                    output.innerText = resultat;

                    // Obtenir le nombre total de patients traités
                    const totalPatients = Module.ccall(
                        'obtenir_nombre_patients', // Nom de la fonction
                        'number',                  // Type de retour
                        [],                        // Pas de paramètres
                        []
                    );
                    patients.innerText = `Nombre total de patients traités : ${totalPatients}`;
                });
            }
        };