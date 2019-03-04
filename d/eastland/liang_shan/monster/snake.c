#include "../takeda.h"
#include "/include/move.h"
#include "conditions.h"
#include "stats.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Gold Snake", "���۹���" );
	add ("id", ({ "snake" }) );
	set_short( "snake","���۹���");
	set("unit","β");
	set_long(@C_LONG
�㿴��һ���ǳ��޴�����ߣ��ֲڵ���Ƥ����ͬʯͷ���Ӳ�����泤��
����\���ɫ��Ƭ������Ľ��ʹ�㿴����ԭ������·����ϸ�����ƺ���
һ��а����������������������̧ͷ������������֪�����ڸ��Ҳ����
�ܹ��������...
C_LONG
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",-3500);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 28);
	set_perm_stat("kar",22);
	set_natural_weapon( 65, 32, 56 );
	set_natural_armor( 75, 30 );
	set ("tactic_func","poison");
	set_skill("dodge",100);
	set_skill("target",100);
	set_skill("black-magic",100);
	set_skill("concentrate",100);
	set("magic_delay",2);
	set("spells/ether-bolt",8);
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"��Ӳ����Ƭ","����������","�޴����ͷ","�ִ��β��"}));
	set_c_verbs( ({"%s���������壬��ȻϮ��%s","%s����������ľ�ס%s","%s���һ��ǿ����Һ������%s"
	,"%s�ſ�Ѫ���ڣ�һ��ҧ��%s"}));
        set( "inquiry", ([
              "cycle": "@@ask_cycle",
              "���" : "@@ask_chiyu",
              "lair" : "@@ask_lair",
              "dragon" : "@@ask_dragon",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "chuyin" : "@@ask_chuyin"
              ]));
}
void evil_damage()
{
     if ( find_call_out("evil")==-1 )
            call_out("evil",5,0);
}
void init()
{
     ::init();
     evil_damage();
}
void evil(int call_again)
{
     object npc,room,*player;
         int i;
          
         npc=this_object();
         room=environment(npc);
         player=all_inventory(room);
         for(i=0;i<sizeof(player);i++)
         if ( living(player[i]) && player[i]!=npc ) {
         tell_object(player[i],
         "�ӽ��۹������Ϸ���ǿ�ҵ�������������.\n");
         player[i]->receive_special_damage("evil",10+random(20));
         "/d/magic/magic"->report( this_object(), player[i] );
         }
         call_again++;
         if ( call_again<5 ) call_out( "evil", 8 , call_again );
         }

void ask_lair()
{
write (@C_LONG
��е����۹������������˵��: �����Ѩ���ҵ����Ⱦ�Ӥ(chuyin)�������ģ�
C_LONG);
      return ;
}
void ask_cycle()
{
write (@C_LONG
��е����۹������������˵��: ���ħ��������һ�ֽ�����
��������һЩ��ǿ���ĺ�ħ��
C_LONG);
      return ;
      }
void ask_chuyin()
{
      write (@C_LONG
��е����۹������������˵��: ��Ӥ������һ����ΰ���Ӣ�ۣ���������
�Ƿ������淨����ǿ�������µĺ�ħ����������Ȼ�����������ȵ����У���
��Ҳ���ֻ��ѧ���˳ɶ���...
C_LONG);     
      return ;
}
void ask_dragon()
{
      write (@C_LONG
��е����۹������������˵��: ����������ڶ�ǿ�������....��һǿ�����
����������
C_LONG );
      return ;
}
void ask_help()
{
      write("���۹�������Ŀ�����......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") < 0 ) {
      write(@C_LONG
��е����۹������������˵��: ร�����������ҵ�θ�ڵģ��ҾͰ���
�����ҵ����°ɣ���˵���������¹ս��֮�ᣬӢ�۾�Ӥ(chuyin)�ӵ����ɽ
������ʼ���������(chiyu)����Ĺ�������
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("���۹���˵��: ���Ǻ��ˣ��������е����.....\n"
             "����������㲻�����⣬������������....\n");
      this_object()->kill_ob(this_player());
            return ;
}
void ask_help3()
{
       write(@C_LONG
���������������ҵ������ǵ�Ŭ��������Ҫ��һ�����ļ���������׼����
�ˣ�Ψ��Ƿȱʹ��ȸ���Ĺؼ��[ ��ȵ��ź� ]��Ŀǰ�����ڿ���ǿ��
�Ķ�λ��Ѱħ�����Ա������Ѱ�ҵ�����ʹ��ȸ���..
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
������Ȼ�ҵ�ħ���ѽӽ���ɣ����������Ҳ��Ҫ����
�����ڿ������ħ��ʱ���ҷ����ƺ�������һ����������ֹ���ǵ�����
���ٵ����꣬��֪������ʲ��仯���������������ܹ����������У���
�ҵ���ȵ��ź����Ҵ��������������㽫����˶��õ��ܴ�ı���...
���������Ļ��������е�������������ֲ�֪�Ƿ��ʵ�
��������˵���Ȼ�ȥ���湫��������ķ����ƺ��Ƚ�ǡ��...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("���������һ������䣬Ϊ���������µİ�Ȩ����Ƶ۴�ս���¹֮Ұ��\n"
      "���⸽�����ǹ�ʱ�����¹....\n");
      return ;
}
void announce( string msg, string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], can_read_chinese(usr[i])? c_msg: msg );
	}
}
void die()
{  
   object ob1,killer,ob2,ob3;
   
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
      tell_room(environment(this_object()),
            "\n���۹���һ��˻��һͷ��ɽ��ײȥ��Ҫ���ܣ���������͸֧����һͷ\n"
            "ײ����ɽ���ϡ����ܵ�ɽ�ھ�������һײ��һ�����ʯƹƹ���ҵĹ�������..\n\n");
   ob1 = new("/d/adventurer/natural_history/stone");
   ob1->move(TROOM"lair/lair5");         
   ob2 = new("/d/adventurer/natural_history/stone");
   ob2->move(TROOM"lair/lair5");
   ob3 = new(TOBJ"rock");
   ob3->move(TROOM"lair/lair5");
   tell_room( environment(ob3),
   "\n�㿴�������СС��ʯͷ��ɽ�Ϲ��������㼯��ȫ����ע�������㣬����\n"
   "û�д���...\n");
   ::die();   
}


int poison()
{
	object victim;

	if( random(20)>4 || !(victim = query_attacker()) ) return 0;
	if( random(3) < 1 ) {
	tell_object( victim, 
		set_color("\n���۾���Ѫ��һ�ţ�һ����ɫ��������Ϯ����\n","HIG",victim));
	tell_room( environment(this_object()), 
		"���۾����޿ڴ󿪣�һ�Ŷ�����" + victim->query("c_name") + "���������£�\n"
		, victim  );
	SIMPLE_POISON->apply_effect( victim, 8, 10 );
	return 1;
	}
	command("cast ether-bolt on "+victim->query("name"));
	this_object()->receive_healing(30);
	return 1;
}
