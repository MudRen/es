#include "/d/eastland/beggar/dony.h"

#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name") 
#define BANDAGED(x)  x->query_temp("bandaged")
        
inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "Doctor Uki", "Сѩ��" );
    add( "id",({"doctor","uki"}) );
    set_short( "һ����ҽ Сѩ��");
    set_long(@LONG
Сѩ�ӿ���ԼĪ��ʮ�ġ���������,ͤͤ����,������,���μ����й������֮
̬��ͬʱ,��Ҳ������Ψһ����ҽ��,��Ȼ����Ͳ���,�ĵ�ҽ�ɵ��洫,����,����
���˻�����꼲����, ������������� ( help )��������,�����������˿���,��
�����ṫ�Ӹ������׷����,��һ�׷���,�����仨����,˭Ҳ��֪������������Щ
ʲ�ᡣ 
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("class","healer");
    set("age",18);
    set("gender","female" );
    set("alignment",1000);
    set("weight",600);
    set("wealth/gold",2);
    set_temp("be_joke",100);
    set_perm_stat("str",19);
    set_perm_stat("dex",26);
    set_perm_stat("kar",30);
    set_perm_stat("int",28);
    set_perm_stat("pie",23);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",300);
    set_natural_armor(20,44);
    set_natural_weapon(21,0,0);
    set_skill("dagger",80);
    set_skill( "bandage",90);
    set_skill("anatomlogy",100);
    set_skill("dodge",75);
    set_skill("parry",70);
    set("stun_difficulty",50);                                              
    set("special_defense", ([ "all": 40,"none":30,"monk":30,"scholar":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":70,"ganglion":70,"weakest":30]) );
    set("stun_difficulty",90);
    wield_weapon(DWEAPON"needle");
    equip_armor(DARMOR"uki_cloth");
    equip_armor(DARMOR"uki_amulet");
    set( "inquiry", ([
              "help":"@@ask_help",
           "bandage":"@@ask_bandage",
               "hau":"@@ask_hau",
               "war":"@@ask_war" 
    ]) );                       
    set( "tactic_func", "my_tactic" );
}        

void init()
{ 
  ::init();
  add_action("do_angry","slap");
  add_action("do_angry","kick");
  add_action("do_angry","kiss");
  add_action("do_angry","flog");
  add_action("do_angry","hold");
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
   call_out("do_kick",4,arg);
}

void do_kick(string arg)
{
    if (arg=="uki"){
       tell_object( this_player(),
          "\nСѩ�ӷ�Թ������˵��:���������С��ȥ���� !!\n\n");
       tell_room( environment(this_object()),
          "\nСѩ���ƺ���"+this_player()->query("c_name")+
          "�ܲ�ˬ��������ȡ����!!\n\n",this_player());
       this_object()->kill_ob(this_player());
       this_player()->block_attack(6);
       this_player()->set_temp("msg_stop_attack","(  ����Ϊ̫���������ס�������� !!  )\n");
       return ;
    }
}
void ask_help( object asker )
{
    tell_object( asker ,
         "Сѩ��˵��:Ŷ,��Ҫ�����?\n"
         "Сѩ������ͣ�ٲ��������̾��һ���� ...\n"   
         "Сѩ�Ӽ���˵��:�����ʦ����,�ǾͿ��԰������,��ϧ.....\n"
         "Сѩ��˵��:����ǰ���з�������,��ʦ������ս��,ֻ����һ�Ű�������,\n"
         "           ������ܸ���һЩ�����Ļ�...............\n");
}

void ask_bandage( object asker )
{
     object ob1;
     
     if ( !asker->debit("gold", 6) ) {
        tell_object( asker, 
          "Сѩ��˵��:�Ұ����������Ҫ�õ㹤���Ѱ�!\n");
        return ;     
     }
     if ( asker==query_attacker() ) {
        tell_object( asker , 
          "Сѩ��ŭ��:��,��𱿵ÿ�����,��������ܰ���˰�����?\n");
        return ;
     }
     if( !present( "bandage",this_object() ) ) {
        tell_object( asker , "Сѩ��˵��:��,������û���κα������԰��㡣\n");
        return ;
     }       
     if ( HP(asker)==MAX_HP(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "Сѩ��˵��:��,��úõ���\n");
        return ;     
     }
     if ( BANDAGED(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "Сѩ��˵��:Ŷ,���ƺ�����������...\n");
        return ;    
     }
     command( "look "+NAME(asker) );
     command( "bandage "+NAME(asker) );
     command( "smile "+NAME(asker) );
     tell_object( asker, 
        "��ܸм������� ( kiss ) Сѩ��һ����Ϊ����,���������־��ò��ס�\n");
     return ;                 
}

void ask_hau( object asker )
{
    if ( asker->query_temp("keeper_finish1") ) {
       tell_object( asker ,
          "Сѩ��˵��:Ŷ,�����ʷ�������������?\n"
          "����Сѩ�ӱ������������¡�\n"
          "Сѩ��˼����һ�����\n" 
              );
       asker->set_temp("uki_asked",1);
       call_out("recover1",10,asker);
    } else 
       tell_object( asker,
          "Сѩ��˵��:�Ҳ�֪����\n");
}

void recover1( object obj)
{
    tell_object( obj ,
       "Сѩ��˵��:��,��Ҳ��֪��Ϊʲ�������,��ֻ֪���������������������\n"
       "           ��,��ȥ��� ���� ��Ժ�� ��,����þÿ���֪��Щʲ�ᡣ\n"         
       "\n��������Сѩ���Ǹ���ӹҽ��\n"
                );
}
void ask_war()
{
write(@C_LONG
Сѩ��˵��:�ǵ����Һ�С��ʱ��,���﷢����һ������,��,��ʦ����������ʱ��������
           ����.......
Сѩ���ƺ���̫��˵��           
C_LONG
    );
}
int my_tactic()
{
     object victim;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if ( victim->query("conditions/herb_apply") ) {
        tell_object(victim,
          "Сѩ�ӿ�Ц��:����������,������ǰ����Ϳҩҩ?��ɵ��!!!\n");
        victim->delete("conditions/herb_apply"); 
     }      
     select=random(10);
     if ( select > 4 ) set("aiming_loc","critical");
     else if ( select > 1 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
        if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
        else set("aiming_loc","vascular");
     }
     return 0;          
}                  