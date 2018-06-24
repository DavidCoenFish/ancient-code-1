#file: Coretech/Code/SConscript

###########################################
# import

Import( "env" )
env = env.Clone()

###########################################
# invoke children sconscripts

# call children SConscript files
env.SConscript(
  [ 
    'Hubris/SConscript',
    'Envy/SConscript',
    'Pride/SConscript',
    'Sloth/SConscript',
    'Vanity/SConscript',
    'Lust/SConscript',
    'Greed/SConscript',
    ],
  exports = {
    "env" : env
    },
  )

#end file