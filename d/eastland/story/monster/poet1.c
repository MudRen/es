#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "poet","����ʫ��" );
    add ("id", ({ "poet" }) );
    set_short( "����ʫ��");
    set_long(@LONG
һλ��������������������ʫ�ˣ������ɰ��Ĵ���ɽ��������̽�ù��ˣ�·����
�ؼ��羰�кã���������ͤ��΢С�һ�����ְ�ͤ����������֮��������������
ʱ��أ����������ʫ����֮�
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",30);
    set("gender","male" );
    set("alignment",100);
    set("weight",1000);
    set("max_fp",200);
    set("wealth/silver",200);
    set_perm_stat("str",23);
    set_natural_armor(75,5);
    set_natural_weapon(28,14,30);
    set_skill("unarmed-parry",50);
    set_skill("dodge",80);
    set_skill("unarmed",70);
    set("special_defense", ([ "all": 20,"none":20]) );
    set("stun_difficulty",30);
    set("couples",1);
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "����ʫ����̸������֪�����Ž����ҹ���ʲ����ζ��\n"
    }) );
}        
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couples") ) return 1;
        return 0;
}
int my_tactic()
{
    object *couples,victim;
    int i,max;
                        
    if( !victim=query_attacker() ) return 0;
                            
    couples = filter_array( all_inventory(environment(this_object())),
          "can_help", this_object() );
    max=sizeof(couples);
    for( i=0; i<max; i++ ) {
       tell_room( environment(this_object()), sprintf(
          "%sŭ�����ߣ�����Ϊ����������֮������ĪҪ��������̡�\n"
          ,couples[i]->query("c_name")));
       couples[i]->kill_ob(victim);
    }
    return 0;
}