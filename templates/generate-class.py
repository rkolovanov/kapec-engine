"""
    GenerateClass script.
"""

from datetime import datetime
from string import Template
from helpers import to_header_format

headerTemplateFilePath = "class.h.template"
sourceTemplateFilePath = "class.cpp.template"

projectName = "kapec-engine"
projectNamespace = "kapec"
projectDescription = "3D-движок на C++ и SFML"

namespaceName = input("Название пространства имен: ")
className = input("Название класса: ")
headerFileName = "{}.h".format(className)
sourceFileName = "{}.cpp".format(className)
header = to_header_format("{}_{}_{}_H".format(projectNamespace, namespaceName, className))

templateValues = {
    "projectName": projectName,
    "projectNamespace": projectNamespace,
    "projectDescription": projectDescription,
    "namespaceName": namespaceName,
    "className": className,
    "classHeaderIncludePath": "{}/{}/{}.h".format(projectName.lower(), namespaceName.lower(), className),
    "year": datetime.now().year,
    "headerFileName": headerFileName,
    "sourceFileName": sourceFileName,
    "header": header
}

with open(headerTemplateFilePath, "r") as templateFile:
    template = Template(templateFile.read())
    content = template.substitute(templateValues)

    with open(headerFileName, "w") as outputFile:
        outputFile.write(content)

with open(sourceTemplateFilePath, "r") as templateFile:
    template = Template(templateFile.read())
    content = template.substitute(templateValues)

    with open(sourceFileName, "w") as outputFile:
        outputFile.write(content)
