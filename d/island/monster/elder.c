//#include "../island.h"
#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Daemon Elder Ivan","ħ�峤�� ����" );
	add ("id", ({ "daemon", "elder", "ivan", }) );
	set_short( "ħ�峤�� ����" );
	set_long(@LONG
����ħ�����ڴ���Ĵ���������������ѵ��ħ��սʿ���£����������
���й�ѵ������(train)��	
LONG
	);

        set( "gender", "male" );
        set( "race", "daemon" );
        set( "unit", "��" );
	set_perm_stat( "dex", 1 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "kar", 1 );
	set("no_attack",1);
	set("no_steal",1);
        set ("weight", 300);
        set( "inquiry", ([
         "train" : "@@ask_train" ,
         "drill" : "@@ask_drill"
           ]) );
}

//void init()
//{
//     ::init();
//     add_action("to_comfort","comfort");
//}

void ask_train(object who)
{ 
  tell_object(who,"����͵͵������˵�������ѵ�����£����ǻ�������ϣ��ѵ��һ���м���ӣ�\n");
  tell_object(who,"  ���Ի���̫��������ǲ��յģ�������Ե���Ҫ��̫ǿ����ϣ���㲻Ҫ����\n");
  tell_object(who,"  �����ѵ����Ҫ��ȷʵ��ѵ���Ļ������������й���ѵ����(drill)����\n");
  return;     
}
void ask_drill(object who)
{ 
  int check;
  if((check=who->query_level())>15)
  { tell_object(who,"���������㣺���������Ѿ����������ˣ����ӣ����ȥ���ɡ���\n"); }
  else if(check<7)
  {  tell_object(who,"���������㣺����Ļ������㣬���������ѵ���ĵط��ҵ㣬�ȵ����ԭ�����ɡ���\n"); }
  else
  {
    tell_object(who,"Bmp�ߵ�����ǰ˵:xixi,��Ȼ��ﵽ��Ҫ�󣬵�....������ܻ�û�п��ţ�\n");
    tell_object(who,"���ٵȵȣ���ߴ߸��������wizard�ɡ�    ף�����ˡ�\n");
//  �����ģ�ԭ��������ܻ�δ�У����Ȱ���ԭ����wizard name //����
//  tell_object(who,"�¶��ߵ�����ǰ˵�����������ĩ����������ʱ����д�꣬\n");
//  tell_object(who,"�ҵĹ�����дһ���� 7��15�������ĵط��������һ�����\n");
//  tell_object(who,"�ߴ�ҵġ���\n");
  }
  return;
}  
