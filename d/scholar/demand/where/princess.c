#include <../oldcat.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(12);
	set_name( "princess", "С��Ů" );
	set_short( "С��Ů" );
	set_long(
		 "@@query_long"
		 );
	set( "gender", "female" );
	set( "race", "dragon" );
        set( "likefish",1);
	set( "no_attack",1);
}

string query_long()
{
 if ((int)this_player()->query_quest_level("Dragon_box"))
 {
    set("hit_points",this_object()->query("max_hp"));
    return "�㿴��һ�����Ц�ݵĹ�����������ɫ��˿���·����ڴ��ڹ��;�ɫ��\n";
  }
 else
  {
   set("hit_points",1);
   return "�㿴��һ���Բ��ڴ��Ĺ�����ԭ�������������ֻ��һƬ�԰ף�\n"+
      "�����û����Ϊ�����ҵ�������ҩ���������Ų��˶�á�\n";
  }
}

int accept_item(object me,object item)
{
     if ((string)item->query("name")!="living pill" || (int)me->query_quest_level("Dragon_box")) {
       tell_object(me,
          "С��Ů΢΢��ҡ��ͷ����лл !! ���Ҳ���Ҫ�ⶫ�� !!��\n");
       command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
       return 1;
     }
     if (!item->query(me->query("name"))) {
        printf("����˵���Ҿ�������Ҳ������Դ�������Ķ�����\n");
        item->move(me);
        return 1;
     }
     tell_object(me,
"��ѹ���������΢������������ҩ���ù�������ȥ������ҩ�����ᣬ������Ȼ����\n"+
"�ö��ˣ���������˵������֪��������£�лл������ң��Ƕ���ɫõ�廨�����ȥ�ɡ�\n"+"�������ö��ˣ�����ø���û�а׷� !!\n\n"
      );
     if ((string)me->query("class")=="scholar") {
        this_player()->set("demand/water",1);
        write("����˵��Ϊ�˸�л��Ϊ����Ů�������������Ҿ�����һֻˮ���鹩���ٻ����������Ҹ�������\n");
     }
     tell_object(me,set_color("�����������Ӧ����˵����лл��! [���� 5000 �㾭��]\n","HIY"));
     item->remove();
     me->finish_quest("Dragon_box",1);
     me->gain_experience(5000);
     return 1;
}
