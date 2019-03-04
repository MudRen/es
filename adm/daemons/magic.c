// This is the magic daemon
// By Annihilator@Eastern.Stories, 11-12-94

#include <magic.h>

#define SPELL_PREFIX "/d/magic/"

// The spell systems are group of spells. Each system is a subdirectory
// in /d/magic
string *spell_systems = ({
	"elemental/",
	"white-magic/",
	"black-magic/",
	"misc/",
});

mapping brief_names = ([
	"hps" :	"heart-protect-shield",
	"es" :	"energy-shield",
	"ltn" :	"lightning",
	"eb" :	"ether-bolt",
	"mgs" :	"magical-shield",
	"mgc" :	"magic-cube",
	"fb" :	"fireball",
	"fs" :	"flamming-shield",
	"dh" :	"detect-hide",
	"is" :	"ice-shield",
	"di" :	"detect-invis",
	"hg" :	"heart-griping",
	"lt" :	"light",
	"sl" :	"sleet",
	"fl" :	"flare",
	"we" :	"wizard-eye",
	"mrs" :	"mirror-shield",
        "ag" : "astral-gate",
        "stm" : "star-memory",
]);

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

/* ֧Ԯ������д 		by EGA 06/09/95 */
string alias_spell(string spell)
{
	return (string)brief_names[spell];
}
