#include "mudlib.h"

inherit MONSTER;

void create()
{
        
        ::create();
        set_level(19);
        set_name("ice_girl","��Ů ѩ��");
        add ("id", ({ "girl", "ice","lulu" }) );
        set_short("ice_girl", "��Ů ѩ��");
        set_long(
    "�����ɱ�֮��������ı�Ů,������Ѱ�������ֳ���Ӱ,��ɱ�\n"
    "�����Ǹ���Ů�Ӿ��۸���,������ܾ�Ҫ�Һ��޳�������!!\n"
       );

        set("alignment",-1000);
        set( "gender", "female" );
        set( "race", "daemon" );
        set( "unit", "��" );
        set( "forgetful", 1 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "pie", 20 );
        set ( "hit_potion" ,1000);
        set ( "wealth" , ([ "silver": 2000 ]) );
        set_natural_weapon(35,10,20);
        set_natural_armor(40,40);
        set ("exp reward",24000);
        set ("chat_chance",15);
        set ("chat_output", ({
             "the girl say:do u see my brother?\n",
             "ѩ��΢Ц��˵:��֪���Ҹ���Ӱ��������? \n"
            }) );
        set("special_defense",(["all":50,"none":40]) );
        set("aim_difficulty",(["critical":5,"weakest":100,"vascular":100]) );
        set_c_verbs( ({"%s����һ������˦��%s","%sһ�С�����ȭ�����%s",
                       "%sһ�ǡ������ȡ�����%s"}) );
        set ("weight", 400);
        set_skill("dodge",100);
        set_skill("parry",100);
        set( "tactic_func", "att_gonfus");
}
int att_gonfus()
{
    object victim;
    int dam;
    
    if( !(victim = query_attacker())  || (random(20)>2) ) return 0;
       tell_room( environment(this_object()), ({"\n",
       "\n\nѩ��˫��һץ,һ������"+victim->query("c_name")+"����ʮ��������\n\n"
        }) );
      dam= 40 + random(30);  
      victim->receive_special_damage("evil", dam );
      return 1;
    }
   
  

