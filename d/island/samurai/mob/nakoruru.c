#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Nakoruru","�ȿ���");
	add( "id", ({ "nakoruru" }) );
	set_short( "Nakoruru","�ȿ���");
	set_long(@AAA
�ȿ�����һ�����ʮ��.�������Ů������һ�������������߹�����ʣ�����һ˫
�鶯�۾�����һ���������õ����ܹµ������ӣ���������԰���������
AAA
 );
	set( "unit", "λ" );
	set( "race", "human" );
	set( "gender", "female" );
	set( "forgetful",1);
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 30 );
        set_perm_stat( "pie", 25 );    
        set( "max_hp",750 );
        set( "hit_points",750 );
	set_natural_armor( 80,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":15,"cold":30,"none":15 ])); 
        set( "stun_difficulty",17);  
	set( "alignment", 2000 );
	set_c_limbs( ({ "ͷ��", "����", "����", "�ʺ�" ,"ǰ��" }) );
        set_skill( "parry",100 );
        set_skill( "dagger",80 );
        set_skill( "dodge",100 );
        set_skill("tactic",100);
        set("tactic","melee");
        set( "wealth" , ([ "silver": 400 ]) );    
        wield_weapon(MOBJ"snow_dagger.c");
        equip_armor(MOBJ"snow_cloth.c");
        equip_armor(MOBJ"snow_cloak.c");
        equip_armor(MOBJ"snow_gloves.c");
        equip_armor(MOBJ"snow_amulet.c"); 
        set( "inquiry",([
             "help":"��ʵ����Ϊ�ҵ����ѼӶ�����(Calford)�����û������\n"
                    "��,���ҵ�������Ҫ����,�����񶼲�����,������....",
             "calford":"�Ӷ������������������ⲿ����ѵ����,��Ҳ�����������ѵ\n"
                       "ֻϣ���������ʱ������һ���ҵ�����,����֪����������.\n"
                       ]));       
}
int accept_item(object player,object ob)
{
         if( !ob->query("nakoruru_statue") ) return 0;
         if( !player->query_temp("calford") ||
                !ob->query("statue_getter") ||
		(string)ob->query("statue_getter") != (string)player->query("name") ) {
            write("�ȿ���ЦЦ��˵���Һܸ�л��Ϊ���Ҷ��������ҵĵ��񣬵��ҵ��������ǼӶ�����..\n");
            command("give statue to "+(string)player->query("name") );
            return 1;
           }
          else{  write(@AAA
�ȿ��贸��˵�˵��ԭ������û�����ң����ǵø������ʵ�ں�лл��İ�æ��

�ȿ���˵����͵͵�������������һ�£�����

AAA
);
             tell_room(environment(player),
   "�ȿ������µ���������¶���ǳ��Ҹ��ı���\n"
                        );
             ob->remove();
             if( (int)player->query_quest_level("nako") <1  ){
                  player->finish_quest("nako",1);
                  write(@AAA
   
��������ȿ�������õ�����ֵ1500

AAA
                    );
                       player->gain_experience(1500);
                       return 1;
               }   
       }
}
