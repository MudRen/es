#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "daughter unary", "�¶�" );
    add( "id",({"daughter","unary"}) );
    set_short( "ȫ��������Ů�� �¶�");
    set_long(@LONG
�¶�������ԼĪʮ�塢�������,��ü����,˫ü���Դ�һ˿Ӣ��,ƽʱ���Աȡ���
ľ����֮��,���н��ŮӢ��֮ò������ƽ�������,·����ƽ�����ε�����,����
����ò�Ҫ�������, �������Ͽ����޷��ưո��ݵġ�
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("class","healer");
    set("age",17);
    set("gender","female" );
    set("alignment",6000);
    set( "forgetful",1);
    set("weight",600);
    set("wealth/silver",420);
    set_perm_stat("str",23);
    set_perm_stat("dex",22);
    set_perm_stat("int",23);
    set("hit_points",500);
    set("max_hp",500);
    set_natural_armor(40,28);
    set_natural_weapon(12,15,20);
    set_skill("dodge",70);
    set_skill("parry",75);
    set_skill("blunt",80);
    set_skill("anatomlogy",85);
    set("special_defense", ([ "all": 50,"none":30]) );
    set("aim_difficulty",
    (["critical":65,"vascular":40,"ganglion":70,"weakest":65]) );
    set("stun_difficulty",90);
    set("aiming_loc","weakest");
    wield_weapon(DWEAPON"seven_blunt");
    equip_armor(DARMOR"seven_gloves");
    equip_armor(DARMOR"seven_boots");
    equip_armor(DARMOR"seven_cloth");
    set( "inquiry", ([
              "father":"@@ask_father",
                 "uki":"@@ask_uki"
    ]) );
}        

void init()
{ 
  ::init();
  add_action("do_angry","slap");
  add_action("do_angry","kick");
  add_action("do_angry","kiss");
  add_action("do_angry","hold");
  add_action("do_angry","flog");
  add_action("do_angry","lkiss");
  add_action("do_angry","smirk");
  add_action("do_angry","excite");
  add_action("do_angry","puke");
  add_action("do_angry","snort");
  add_action("do_angry","bite");
  add_action("do_angry","lick");
  add_action("do_angry","bark");
  add_action("do_angry","fart");
  add_action("do_angry","spit");
}

void do_angry(string arg)
{
   call_out("do_kick",2,arg);
}

void do_kick(string arg)
{
    if (arg=="unary"){
       tell_object( this_player(),
          "\n�¶���Թ������˵��:���������С��ȥ���� !!\n\n");
       tell_room( environment(this_object()),
          "\n�¶��ƺ���"+this_player()->query("c_name")+
          "�ܲ�ˬ��������ȡ����!!\n\n",this_player());
       this_object()->kill_ob(this_player());
       this_player()->block_attack(8);
       this_player()->set_temp("msg_stop_attack","(  ��̫ʧ����,�������ס�˶������� !!  )\n");
       return ;
    }
}
void ask_father( object asker )
{
     tell_object( asker,
       "�¶�˵��:��,�����ҵ����?�Ҳ�֪����������Ү��\n"
       "�¶�̾��:��,������֪����ʲ��ط����������游������,��������������,\n"
       "         һֱ������Ҫ�����游���⼸�첻֪������������һ����ֵ���,��\n"
       "         ������֮��,�����Ͳ��������ˡ�\n"
       "�¶�˵��:����,�����ȥ�����,�����ҵ������ˡ�\n"
       );
     asker->set_temp("unary_asked",1);
}
void ask_uki()
{
write(@C_LONG
�¶�а���˵��:Сѩ���,���ز��ܴ�Ӵ!!
C_LONG 
    );
}