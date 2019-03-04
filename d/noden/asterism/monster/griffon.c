#include "../asterism.h"

inherit MONSTER;
inherit MOUNT;

void create()
{
    ::create();
    set_level(16);
    set_name( "griffon", "ʨ����" );
    add("id",({"griffon"}) );
   set_short( "ʨ����" );
    set_long(
	    "���˵Ĵ�˵��Ϊʨ��������������硣����������������վ������ǰ��\n"
	);
    set( "gender", "neuter" );
//    set( "race", "griffon" );
    set( "unit", "ֻ" ) ;
    set( "alignment", 200 );
    set( "time_to_heal", 8 );
    set("max_hp",300);
    set("hit_points",300);
    set("forgetful",1) ;
    set("max_load",2500) ;
    
    set_natural_armor( 40,20 );
    set_natural_weapon( 40,21,33 );
    set_perm_stat( "str", 23 );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "kar", 30 );
        
    set("special_defense",(["all":40,"none":0]));
    set("aim_difficulty",(["critical":10,"weakest":50,
                         "vascular":30,"ganglion":40 ]) ) ;

    set( "c_extra_look", "$N������һֻ�ߴ��ʨ�����ϡ�\n");
    
    set_c_verbs(({"%s��������צ��%sץȥ","%s������������%sҧȥ"}));
    set_c_limbs(({"����","ͷ��","���","��"}));    
    
    set_skill("dodge",65)    ;
    set_skill("unarmed",50) ;
    equip_armor(ARMORS"mithril_saddle");
    set( "wealth/gold", 5 );	
    set("is_griffon",1) ;
    set("echo_asterism",1) ;
    set( "tactic_func", "cast_help" ); 
}
void init()
{
//        monster::init();
        mount::init();                
}

int cast_help()
{
   int i ;
   object train ;
   
   if(!present("dwarf trainer"))
     {  
        i = (int)this_object()->query("aa")+1 ;
        set("aa",i ) ;
        if( i==3 )
           this_object()->delete("forgetful") ;
      }      
      
   return 0 ;
}

