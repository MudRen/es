#include "../legend.h"

string *cast_msg1=
     ({ "%s��ʼ���ۿ����еķ�������������Χ�γɾ޴�ı��磡\n",
        "%s���п�ʼð������İ��̣����Щ΢����!\n",
        "%s����������еĹ����Ӳ��ϵؾۼ�!\n" }),
       *cast_msg2=
     ({ "%s���Եı��缱�ٵ���������ǰ�ι�����е�һ��������Ĵ�ʹ��\n\n",
        "\n%s���д󺰡�������𡹣����������������Ͻ�ȥ��ʹ����ʹ�ѵ�!\n\n",
        "%s��Χһ��ǿ��Ĺ�����������������!\n\n\n\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "fisher captain","�峤" );
	add ("id", ({"captain"}) );
	set_short("��� �峤");
	set_long(@C_LONG
�峤��Լ�ġ���ʮ�꣬һ����ʿ�����ӣ������������Ƶģ����ǣ���һ����Ƣ����
�Ƿǳ��ֲ��ģ����ı�������˵���Դ�����ͷţ�����ĺ�����������ֻ���󶼴´�
���ţ����ԣ�����ò�Ҫ������Ӵ���峤ͬʱ�Ǵ��������Ȩ�����ˣ�ƽʱ�ƹ���
����ͷ���СС�����񣬿�˵�Ƿǳ�æµ���峤����ڸ�������ѧϰһЩ��������
Ȼ���������˸ĸ�����Ƣ���������ٺò����ġ��峤���ڳ�ü�������ƺ�������
ʲ���鷳�ˡ�
C_LONG
	);
	set( "unit", "��" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "kar", 30 );
        set("weight",900);
        set_skill( "unarmed-parry", 80);
	set_skill( "dodge", 80 );
	set("max_sp",2700);
        set("spell_points",2700);
	set_temp("be_joke",100);
	set("hime_to_heal",4);
	set( "special_defense", ([ "all": 50,"none":50,
	"monk":40,"scholar":20]) );
	set( "stun_difficulty",50);                                              
	set("aim_difficulty", 
	   ([ "critical":100, "vascular":60, "ganglion":70, "weakest":30 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set("max_hp", 900);
	set("hit_points",900);
	set_natural_armor( 60,35 );
	set_natural_weapon( 72,29,55);
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(LARMOR"fish_cloth");
//	set( "tactic_func", "my_tactic" );
        set( "inquiry", ([
             "trouble":"@@ask_trouble",
                "�鷳":"@@ask_trouble" 
        ]) );
}
void ask_trouble(object asker)
{
   if ( asker->query_temp("second") ) {
      tell_object(asker,"�峤�����ĵؿ�����\n");   
      return ;   
   }
   if ( asker->query_temp("captain_asked") ) {
      tell_object(asker,"�峤�����������ˡ�\n");
      return ;
   } 
   asker->set_temp("captain_asked",1);
write(@C_LONG
�峤��̾��һ�������������ұ��и���÷�����Ů�ѣ����������ۼ���޵ĳ̶ȣ���
�����������ڰ������ζ������������ã������ţ���ʱ����Ӧ������һ���������
������������ʱ�⡣���ҵأ���һ�죬����һ�����Ų������ں����ϣ��͵أ�һ����
�����������˰��������˺���ȥ�����ᣬ���ɹ�����������ͨˮ�Ե���ȥѰ������
�����������ݼ���ȴһֱ��Ѷȫ�ޣ�����֪���������������������ʮ����������
�����������Ҳ費˼�����룬��ʱ���̲���������ڣ���Ը���������е�һ�У�ֻ
����������Ϊ�ܻ�����һ˿�����ա����������ܰ���ȥ��Ѱ���𣿰�������

�峤�����������С�棬С�棬��֪�����Ƕ�����������𣮣���
C_LONG
     );
} 
int my_tactic()
{
    object victim,env;
    string mob_name,msg1,msg2,type;
    int damage;
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    mob_name=query("c_name");
    switch( random(50) ) {
    case 1..5:
       msg1=set_color(cast_msg1[0],"HIB");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIB");    
       type="energy";
       damage=55+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 6..10:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=80+random(25);
       call_out("cast_run",5,type,msg2,mob_name,damage);
       break;
    case 11..15:
       msg1=set_color(cast_msg1[2],"HIY");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"HIY");
       type="electric";
       damage=65+random(20);
       call_out("cast_run",4,type,msg2,mob_name,damage);
       break;
    }
    return 0;              
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   for (i=0;i<sizeof(all);i++)
      if ( all[i]!=this_object() ) 
         all[i]->receive_special_damage(type,damage);      
}
void relay_message(string class, string msg)
{

     string who, str;
     object player;

     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)���˽�����", str,who )==2 ) {
     if( !player = find_player(lower_case(who)) ) return;
     if( !player->query_temp("wife_asked") ) return ;
     player->delete_temp("wife_asked");
     player->delete_temp("captain_asked");
     player->set_temp("second",1);
     tell_object(player,@C_LONG
�峤�����������������ŮС�桹������ѶϢ���ɵ�ʹ����һ�������˲����Լ�����

�㿴���޳������ӣ�������ȥ���������㲻����̾�����������컯Ū�ˣ�������ʹ��
�����ճɾ�����Ҳ�����ϻ�����һ�����ĵ����ˡ���

C_LONG
     );                                                               
     }
}