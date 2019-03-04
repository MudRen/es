#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Silver Dragon","��������" );
	add ("id", ({ "dragon" }) );
	set_short( "dragon","��������");
	set("unit","β");
	set_long(@C_LONG
����һ������������ɫ�ۼ׵ľ��������������޴��������ı���
�ڴ�˵�����Ǿ��в���˼���������������ޣ��κ�����ֻҪ����������Ѫ
�Ϳ�����������������������˵�ܾ���ǰ�и�����˼����ʿ���õ�����Ѫ
���Ƴ���Ѫǹ��
C_LONG	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",2700);
	set("max_hp",800);
	set ("time_to_heal", 1);
	set("hit_points",800);
	set_perm_stat("str", 30 );
	set_perm_stat("dex", 23 );
	set_perm_stat("kar", 25 );
	set_skill("dodge",100);
	set_natural_weapon( 80, 45, 72 );
	set_natural_armor( 130,60 );
	set ("gender", "male");
	set ("race", "monster");
	set_c_limbs(({"��Ӳ�ı���","ǰ��","�ִ�ĳ�β","ͷ��"}));
	set_c_verbs( ({"%s������צץ��%s","%s����һ������β��ɨ��%s",
	"%s���죬һ���������%s"}));
        set ("tactic_func","special_attack");
        set( "inquiry", ([
              "laice" : "@@ask_laice",
              "blood" : "@@ask_blood",
              "dragon" : "@@ask_dragon",
              "snake" : "@@ask_snake",
              "help" : "@@ask_help",
              "chiyu" : "@@ask_chiyu",
              "���" : "@@ask_chiyu",
              ]));
}
void ask_laice()
{
write (
      "����ս��ͻȻ�����������ӣ����: �Ǹ������ļһ˵��Ҫ�����ҵģ�\n"
      "�������Լ���Ѫ(blood)ǿ�����������ᣬ���Ͳ�֪������?\n");
      return ;
}

void ask_blood()
{
      write (
      "����ս��˵��: �Դ��ϴα���˼ƭ��֮�ᣬ����Ҳ�������κ����ˣ�\n"
      "��Ҫ�ҵ�Ѫ�����ǰ���ɱ�ˣ���Ҫ����Ȥ������....\n"
      "˵�꣬����ս���ñ����������ϴ�����\n");
      return ;
}
void ask_dragon()
{
      write (
      "����ս��˵��: ������������ǿ�������....�ҵ����Ⱦ��Ǵ�˵�е�Ӧ��...\n"
      "���������Ƶ۴�����...\n" );
      return ;
}
void ask_snake()
{
      write (
      "����ս��˵��: ���������������? ���Ǵ�˵����ȵ����¾�Ӥ�������\n");
      return ;
}

void ask_help()
{
      write("�Ҹ���������? ����ս�����ɵĿ�����......\n");
      call_out("ask_help2",10,this_player());
      return ;
}
void ask_help2()
{
      if ( this_player()->query("alignment") > 0 ) {
      write(@C_LONG
����ս��˵��: �ðɣ�����Ҳ��������ˣ��Ҿ͹����������...
��˵�����(chiyu)����¹ս��֮�ᣬ�������¾�Ӥ�ӵ����ɽ����
���ܽ�������ȸ������ı����������Ӧ�������ˣ������Ҳ������
��ɽ������������½���԰��ؽ����ƻ������񣬲���������񴫳�
�����������ǡ�
C_LONG
            );
            call_out("ask_help3",10,this_player());
            return ;
            }
      write("���ǻ��ˣ�һ������ֻ���ߵ�����....�����.....\n"
            "˵����������.....\n");
            return ;
}
void ask_help3()
{
       write(@C_LONG
���������������ҵ������ǵ�Ŭ������Ща��Ķ���ʼ��û���ҵ�
ʹ��ȸ���Ĺؼ��[ ��ȵ��ź� ]��������������е�֪��Ŀǰ��Ӥ      
��������м�ǿ�ĺ�ħ������������Ŀǰ���ڿ���ǿ���Ķ�λ��Ѱħ����
���Ǳ��������ɹ�����ֻ����������Σ�գ������ܱ����ȷ�����ȵ��ź�
��ʱ����ȸ�������������....
C_LONG
       );
             call_out("ask_help4",10,this_player());
             return ;
}
void ask_help4()
{
        write(@C_LONG
Ŀǰ�ĵ���֮���ǣ������ǿ�������λ��Ѱħ��ǰ�����ҵ���ȵ��ź�
���Ҵ����������������������������£��ҽ��ᾡ�����ܵĻر���
ǧ��Ҫ������ս��ֻ���ߣ������������������������ܻᷢ��Σ��
�����ʹ��ʧȥ��׷�����ǵ�����....
���������Ļ��������е�������������ֲ�֪�Ƿ��ʵ�
��������˵���Ȼ�ȥ���湫��������ķ����ƺ��Ƚ�ǡ��...
C_LONG
              );
        this_player()->set_temp("find_something",1);
        return ;
}              
void ask_chiyu()
{
write("������Ϲ�ʱ�Ĵ�ħͷ��Ϊ���������µİ�Ȩ����Ƶ۴�ս���¹֮Ұ��\n"
      "���⸽�����ǹ�ʱ�����¹....\n");
      return ;
}
void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   ob1 = killer->query("weapon1");
   if( !killer ) {
     ::die();
     return;
   }
   if( !ob1 ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      killer->query("c_name")+"һ����𣬽����е�"+ob1->query("c_name")+"������ս��������ȥ...\n"+
      "\n����ս������ѣ�¡¡֮������춶���תͷ��"+killer->query("c_name")+"����������һ�� ��\n\n\n");
      killer->set("hit_points",10);
      "/d/magic/magic"->report( this_object(), killer );
   tell_room(environment(this_object()),
      "����һ���ᣬս����춲�֧����Ѫ���ض���....\n"+
      killer->query("c_name")+"������ս�������ϵ�"+ob1->query("c_name")+
      "�γ���˳�ְ������Ѫ������Ǭ����\n"      
      );
   ob1->add( "min_damage",5 );
   ob1->add( "max_damage",5 );
   ::die();   
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
       
       
int special_attack()
{// 10% use it! damage 30-50.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "\n\n [1;41m �������һ�����������յ��������紦������㣮 [0;40m \n\n\n" ,
      this_object()
    );
    this_object()->receive_healing(10);
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_special_damage("fire",random(20)+30);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

