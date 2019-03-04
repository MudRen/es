#include <../goomay.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "hunter", "���˰���" );
	set_short( "���˰���" );
	set("long","@@query_c_long");
	set( "gender", "male" );
	set( "race", "orc" );
	set( "no_attack",1);
	set("inquiry",([ "health" : "@@ask_health" ]) );
}
void ask_health()
{
if( (int)this_player()->query_quest_level("Goddess_statue") < 2 )
	tell_object(this_player(),
	"���˰����м��ص� �� лл�㣬�Ҿ��úö��ˣ����������ҵ��ҵܵ�С����\n"
	"���ڶμҿ󳡹�����������������֪���ˡ�\n");
else
	tell_object(this_player(),
	"���˰���ˬ�ʵ�Ц�� : лл�� ! ���Ѿ����ˣ�С��Ҳ�����ˣ��治֪���������л�� !!\n");
	return ;
}

string query_c_long()
{
if( (int)this_player()->query_quest_level("Goddess_statue") ){
    set("hit_points",this_object()->query("max_hp"));
    return "�㿴��һ������(health)���ֵ����ˣ���������ͭɫ��Ƥ������������������\n"
     "����ɽҰ��Ӣ�� !! ��������κ���Ҫ������ֱ��������æ��\n";
  }
 else
  {
   set("hit_points",1);
   return "�㿴��һ����������һϢ�Ŀ����ˣ�ԭ����ͭɫ��Ƥ�����ڶ���������ɫ��\n"+
     "�����û����Ϊ������ǲ������ȥ��ҽ�����������Ų��˶�á�\n";
  }
}

int accept_item(object me,object item)
{

     if ((string) item->query("name") !="pack of herbs" || 
         (int)this_player()->query_quest_level("Goddess_statue")>0 ) {
     tell_object(me,
        "���˰�����Ц��ҡҡͷ����лл !! �Ҳ���Ҫ�ⶫ�� !!��\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
"���ҩ�������ز������ˣ����Ұ��������ҩ����������ҩ����İ�����Ȼ����\n"
"�ö��ˣ���������������˵��������һ���ܵܣ��ڶμҵ�����ӹ������ɷ�����\n"
"���Ұ����л��� !! лл !! ��ֻҪ��������˵Ҫ��"+
set_color("С��","HIY")+"�Ϳ����� !! ��\n\n"
"�������ö��ˣ�����ú���ο !! "+set_color("[ �õ� 1500 �㾭�� ]","HIC")+"\n"
		 );
	item->remove();
	this_player()->finish_quest( "Goddess_statue", 1 );
	me->gain_experience(1500);
        return 1;
}
