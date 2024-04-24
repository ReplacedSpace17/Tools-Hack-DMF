#pip install flask

from flask import Flask, jsonify

app = Flask(__name__)

# Ruta para manejar solicitudes GET
@app.route('/api/ejemplo', methods=['GET'])
def obtener_ejemplo():
    # Aquí puedes realizar cualquier lógica necesaria para procesar la solicitud
    # Por ejemplo, puedes preparar datos para enviar como respuesta
    datos = {
        'mensaje': 'Hola desde la API Flask!',
        'estado': 'exitoso'
    }
    # Devolver los datos en formato JSON como respuesta
    return jsonify(datos)

# Punto de entrada para ejecutar la aplicación Flask
if __name__ == '__main__':
    # Ejecutar la aplicación en modo de desarrollo en el localhost en el puerto 5000
    app.run(debug=True)

#para correr python serverFlask.py

