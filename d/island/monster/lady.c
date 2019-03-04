#include <mudlib.h>
inherit MONSTER;

void create()
{
	
	::create();
	set_level(1);
	set_name( "Assistant Rabecca","�ٱ���" );
	add ("id", ({ "lizardman", "assistant", "rabecca", }) );
	set_short( "�������� �ٱ���" );
	set_long(@LONG
�������������¹���Ƹ���С�㣬��������������ǩ֤��ҵ��
����������ɫ���������������ʹ�˸���ɫ�ּ������(carve)����
�е�Сľ��ȥ�ˣ�
LONG
	);

        set( "gender", "female" );
        set( "race", "lizardman" );
        set( "unit","λ" );
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
         "carve" : "@@ask_carve" ,
//         "drill" : "@@ask_drill"
           ]) );
}

void ask_carve(object who)
{ 
  if( !who->query_temp("lizard_quest/get_saw"))
  {
      tell_room( environment(),@LONG
�ٱ���������˵������С����첻���ˣ����˰�ľ��Ҫɱ�ˣ��������
LONG
      );
  }else{
  tell_room( environment(),@LONG
�ٱ������������Ŀ�����˵���ˣ�����Ϊ����ʲ���أ��ҳ��˻������鹤����
�����ֵľ��ǵ��ľ���ˣ�����Ҫ�Ա�ľ�ߣ��Ҳſ�Ϊ���Ŷ��
LONG
      );
  }
  return;
}

int accept_item(object who, object ob)
{
    object obj;
    string *name;
    name=ob->query("id");
    
 if(name[0] == "mahogany branch")
  {
     if( who->query_temp("lizard_quest/get_saw") )
     {
       ob->remove();
       tell_room( environment(),@LONG
�ٱ���������ݸ�������ľ˵:
    �ۣ���·����������ľ��һ���̳ܿ�������Сľ���ģ����Ե�һ��Ŷ��
����˵�꣬���̰�Сľ���ݸ��㣡
LONG
        );
        obj = new("/d/island/hole/obj/kirs");
        obj->move(this_object());
        command("give kirs to "+(string)who->query("name"));
     }else{
       tell_room( environment(),@LONG
�ٱ���ͻȻ����������Ц��:�������ã�����һ����ͷ֮�ޣ�

���������������������Ҹ�������ҿ����������Ҿ���������û���ĵĶ�����������

�ۡ������������������ľ�������ľм��....
LONG
        );
        ob->remove();
     }
      return 1;
  }else{ 
      tell_room( environment(),@LONG
�ٱ�����Ц��:������ⶫ����������лл�ޣ�
˵��˵������������������....
LONG
        );
     ob->remove();
     return 1;
  }
}
