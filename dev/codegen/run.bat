echo Generating Code

Pushd "%~dp0\.."
"codegen/donut-codegen.exe" --p3din "codegen/p3d.json" --p3dout "../src/P3D" --cmdin "codegen/cmd.json" --cmdout "../src" --copyright "Copyright 2019 the donut authors. See AUTHORS.md"