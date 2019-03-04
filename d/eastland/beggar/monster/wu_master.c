#include "/d/eastland/beggar/dony.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "master Wu","���" );
        add ( "id", ({ "master","wu"}) );
        set_short("�Ĵ���֮ ���" );
        set("unit","λ");
        set_long(@C_LONG
������ÿ�������,�ߴ�����,һ˫��׳�ı۰�����������η�����֡� ��
���ֽ�λ���Ĵ������е�һλ,ƽʱ�úȾ�Ϊ�˺�ˬ�Ǹ�ֱ���ӵ��ˡ�����
���ְ��򱧲�ƽ,��������,ͬʱҲ�ǰ�����˷������ܵĺ��ѡ� ���������
�ڸ���������һЩ�������顣
C_LONG
        );
        set("weight",920);
        set("alignment",100);
        set("gender","male");
        set("race","lizardman");
        set("hit_points",700);
        set("max_hp",700);
        set_perm_stat("str",25);
        set_perm_stat("dex",23);
        set_natural_weapon(10, 5, 10);
        set_natural_armor(81,39);
        set( "special_defense", ([ "all": 40, "none": 45 ]) );
        set_skill("parry",60);
        set_skill("block",60);
        set_skill( "axe", 90 );
        equip_armor(DARMOR"silver_tail");
        equip_armor(DARMOR"dragon_shield");
        wield_weapon( DWEAPON"silver_axe" );
        set( "inquiry", ([
                    "war":"@@ask_war",
                   "talk":"@@ask_talk",       
                 "secret":"@@ask_secret"
            ]) );
        set("tactic_func","my_attack");
}
void ask_talk()
{
write(@C_LONG
���˵��:ȥȥȥ,С���Ӳ�Ҫ�ʴ��˵����顣
C_LONG
     );
}
void ask_war()
{
write(@C_LONG
���������ɫ�ƺ���̫��˵��
C_LONG
     );
}
void ask_secret()
{
    if ( !this_player()->query_temp("jail_asked") )
       tell_object(this_player(),"���˵��:ȥȥȥ,С���Ӳ�Ҫ������ʡ�\n");
    else {
       this_player()->set_temp("wu_asked",1);
       tell_object(this_player(),"���˵��:��,��ô�����������ȥ��\n");
    }    
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") )
     name=killer->query("name");
   str="\n  "+ctime(time())+" ��� killed at "+
      file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
}