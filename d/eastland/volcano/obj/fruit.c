#include "../oldcat.h" 

inherit OBJECT;

object place;
void create()
{
	set_name( "manlike fruit", "�˲ι�" );
	set_short( "�˲ι�" );
	set_long(
	  "���Ǹ������������١�ǧ��һ����˲ι���\n"
	);
        add("id",({"fruit"}) );
        set( "unit", "��");
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   int align;

   if(!arg || arg!="fruit")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };
   this_object()->set("prevent_drop",1); 
   write("���������˲ι�֮�ᣬͻȻ��������������ʲ��仯����������\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",5,this_player());
   call_out("end",25,this_object(),this_player());

   return 1;
}

int idle_time1(object who)
{
    tell_object(who, "������������һ�ᣬ������Ʈ���������㲻������͵Ц���ò������ڣţ��л�����ã���춳����ˡ�\n");
    tell_room(environment(this_player()),"\n����� "+this_player()->query("c_name")+" ������Ʈ��������������з���ȥ��\n\n",this_player());
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who, "�㷢���Լ��Բ��ϵ����ߣ������Խ��ԽԶ����춿������ˣ��������������ڰ���У���֪����Ʈ���δ���\n");
    tell_room(place=environment(who),"\n"+who->query("c_name")+"Խ��Խ�ߡ�Խ��Խ�죬�������һ�㣬��ʧ�ڿ����ˡ�\n\n",who);
    who->set_temp("block_command",0);
    who->move_player(OTEMP"void","SNEAK");
    return 1;
}

void end(object ob1,object who)
{
  tell_object(who,"\n���д�����ʦ��è���������Բ������ޡ������������㹦\��Բ��ʱ��\n��Ȼ���˻���������ɡ�\n\n");
  tell_room(place,"\n�����"+who->query("c_name")+"�ӿ���������Ʈ��������\n\n",who);
  who->move_player(place,"SNEAK");
  ob1->remove();
  return;
}
