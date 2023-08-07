project('sokoban', 'cpp')

sfml_dep = dependency('sfml-graphics')
nlohman_dep = dependency('nlohmann_json')
json_schema_dep = dependency('nlohmann_json_schema_validator')

executable('sokoban'
    , 'src/main.cc'
    , 'src/board.cc'
    , 'src/board_validator.cc'
    , cpp_args : ['-std=c++17', '-Wall', '-Wextra', '-Werror', '-pedantic', '-g']
    , dependencies : [sfml_dep, nlohman_dep, json_schema_dep]
)
