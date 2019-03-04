#include <mudlib.h>

inherit MONSTER;

void create()
{
    ::create();
    set_level(14);
    set_name("peacock","��ȸ");
    add("id",({"peacock"}) );
    set_short("��ȸ");
    set_long(@LONG
һֻ�ǳ�Ư�����������¶����ĳ��
LONG
            );
    set("unit","ֻ");
    set_perm_stat( "str", 22 );
    set_perm_stat( "dex", 16 );
    set_perm_stat( "kar", 20 );
    set("weight",650);
    set_skill( "dodge", 80 );
    set( "special_defense", ([ "all": 20 ]) );
    set_natural_armor( 25, 10 );
    set_natural_weapon( 65, 20, 20 );
    set( "natural_weapon_class2", 40 );
    set( "natural_min_damage2", 15 );
    set( "natural_max_damage2", 25 );
    set("chicken",1);
    set( "tactic_func", "my_attack" );
    set_c_verbs( ({ "%s��ǰצץ��%s", "%s����������%s��ȥ" }) );
    set_c_limbs( ({ "ͷ��", "β��", "�Ȳ�" }) );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("chicken") ) return 1;
       return 0;
}
int my_attack()
{
   object *couples,victim;
   int i;
      
   if( !victim=query_attacker() ) return 0;
            
   couples = filter_array( all_inventory(environment(this_object())),
            "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
       tell_room( environment(this_object()), couples[i]->query("c_name")+
             "ŭ��:ɱɱɱ!!\n",couples[i]);
       couples[i]->kill_ob(victim);
   }
   return 0;
}                                                                