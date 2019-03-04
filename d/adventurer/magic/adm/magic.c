#include "/d/adventurer/magic/magic.h"

#define SPELL_PREFIX "/d/adventurer/magic/"
 
 string *spell_systems = ({
       "green-magic/"
       });
string find_spell(string spell)
{
        string sp;
        int i;
                
        sp = replace_string( spell, " ", "_" );
        for(i=0; i<sizeof(spell_systems); i++ ) {
        if( file_size( SPELL_PREFIX + spell_systems[i] + sp + ".c" ) > 0 )
        return SPELL_PREFIX + spell_systems[i] + sp;
        }
  }
  