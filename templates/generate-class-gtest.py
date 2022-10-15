"""
    GenerateTestClass script.
"""

from datetime import datetime
from string import Template

testSourceTemplateFilePath = "class-gtest.cpp.template"

projectName = "kapec-engine"
projectNamespace = "kapec"
projectDescription = "3D-движок на C++ и SFML"

namespaceName = input("Название пространства имен: ")
className = input("Название класса: ")
testName = "{}_Test".format(className)
testSourceFileName = "{}.cpp".format(testName)

values = {
    "projectName": projectName,
    "projectNamespace": projectNamespace,
    "projectDescription": projectDescription,
    "namespaceName": namespaceName,
    "className": className,
    "classHeaderIncludePath": "{}/{}/{}.h".format(projectName.lower(), namespaceName.lower(), className),
    "year": datetime.now().year,
    "testSourceFileName": testSourceFileName,
    "testName": testName
}

with open(testSourceTemplateFilePath, "r") as templateFile:
    template = Template(templateFile.read())
    content = template.substitute(values)

    with open(testSourceFileName, "w") as outputFile:
        outputFile.write(content)
