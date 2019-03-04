#include <../hole.h>

inherit MONSTER;

int cough;

void create()
{
	object obj;
	::create();
	set_level(15);
	set_name( "Old Feller","�Ϲ���" );
	add("id",({ "lizardman","feller" }) );
	set_short( "�Ϲ���" );
	set_long(@LONG
    �㿴������һλ��Լ��ʮ����Ϲ����������������
������һָ�Ĺ���ร������κ�ľ�ĵ��������϶����Ե�
�̳��������Ʒ�����������������ƺ���̫�á�
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",400 );
	set( "max_hp",450 );
	set( "hit_points",450 );
	set( "wealth/silver",150 );
	set( "special_defense",([ "none": 25,"all": 22 ]) );
	set( "aim_difficulty",(["critical":30,"vascular":80]) );
	set_perm_stat( "str",20 );
	set_perm_stat( "dex",20 );
	set_natural_armor( 70,34 );
	set_natural_weapon( 65,25,45 );
	set_skill( "parry",90 );
	set_skill( "dodge",80 );
	set( "inquiry",([ "vampire" : "@@ask_vampire",
	                  "saw"     : "@@ask_saw"  ]) );
//	obj=new( HOBJ"saw" );
//	obj->move( this_object() );
	cough=1;
}

void init()
{
	::init();
	tell_room(environment(),set_color("�Ϲ�����ͣ�ؿ���\n","HIY") );
}
void ask_saw()
{
     if( cough == 0 ){
        if( this_player()->query_temp("lizard_quest/o_feller") ){
         tell_room( environment(),
         "�Ϲ���˵:����Ӱ������԰�����������������Һ��ȣ�\n" );
         this_player()->set_temp("lizard_quest/shark_soup",1);
         this_player()->delete_temp("lizard_quest/o_feller");
         cough = 1;
        }else{
         tell_room( environment(),
         "�Ϲ���˵:��Ҫ����Ӹ�������ˣ��ҿ�ɶ���ӹ���ѽ�����裡\n");
         cough = 1;
        } 
        return;
       }
       tell_room( environment(),
       "�Ϲ���������Ҫ˵ʲ�ᣬ��ȴһֱ���ԣ��������ĺ���������ɣ�\n");
       return;
}

[BBvoid ask_vampire()
{
	if( cough==1 )
	{
	tell_room( environment(),
	"�Ϲ���������˵ʲ�ᣬ��ȴһֱ���ԣ��������ĺ���������ɣ�\n" );
	return ;
	}
	tell_room( environment(),"�Ϲ���˵:��Ѫ������û���˿�����\n" );
	cough=1;
	return ;
}

int accept_item(object me,object item)
{
	string *name;
	object ob;
	
	name=item->query("id");
	if( name[0] == "paste" ){
	      command( "drink paste" );
	      cough=0;
	      return 1;
	}else if( name[0] == "soup" ){
              if( me->query_temp("lizard_quest/shark_soup") ){
              tell_room( environment(),@LONG
�Ϲ���������֮�ᣬЦЦ����˵��
�������ã��ɵúã������ճ�ŵ�Ѿ��ӽ�����ޣ�
LONG
              );
              ob = new(HOBJ"saw");
              ob->move(this_object());
              command("give saw to "+(string)me->query("name") );
              me->set_temp("lizard_quest/get_saw");
              me->delete_temp("lizard_quest/shark_soup");
              return 1;
              }else{
              tell_room( environment(),
          "�Ϲ����������ᣬЦЦ��˵��С�ӣ�лл�������������Ļ��кñ��ģ�\n");
              item->remove();
              return 1;
              }
              }else{
	      tell_room( environment(this_object()),"�Ϲ���˵�������ϷŪ�������˼ҡ���\n" );
	      command( "give "+name[0]+" to "+lower_case( (string)me->query("name") ) );
	      return 1;
              }
}
