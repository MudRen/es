#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;
int bee_out=0;
void create()
{
        set_name("amazing flower", "����֮��");
        add ("id",({ "flower"}));
        set_short("����֮��");
        set_long(
                 "����һ������߲ʻ���Ļ���\n"
                 "���Ļ����ǣ�û�в����ܵ��¡�\n"
                 "��仨�ϻ�ϵ��һ��С��Ƭ��\n");
        set("unit", "��");
        set( "weight", 1 );
        set ("value", ({ 10, "silver" }) );
        set("message","BLANK");
	set("no_sale",1);
	set("c_smell","һ���߱ǵ�ܰ��ֱ͸������ķ�������о��������ȫ����̹��");

}
void init()
{
	add_action("write_msg","write");
	add_action("read_msg","read");
	add_action("look_card","look");
	add_action("smell_me","smell");
}
string get_c_sex(object who)
{
	string sex;
	sex=who->query("gender");
	if (sex=="male")
	  return "����"; 
        if (sex=="female")
          return "����";
	return "����" ;
}
int look_card(string arg)
{
	if (arg !="card")
	return 0;

	write(
		"����һ��Ʈ�����»���Ľ��С��Ƭ��������Ϊ���Ǵ��͸�ֱ�ӵ����⡣\n"
		"���������������дЩʲ�ᡣ\n" );
	return 1;
}
int write_msg(string arg)
{
	string msg,item;
	object target;
	if ( !arg || arg=="" || sscanf(arg,"%s on %s",msg,item) != 2) 
	  return notify_fail(
			"ҪдЩʲ���أ� Syntax : write <message> on <flower>.\n" );
	target = present(item, this_player());
	if(!target)
		return notify_fail("��û�����ֻ�....��\n");
	
	if ((string)target->query("message") != "BLANK")
          return notify_fail(
			"���ſ�Ƭ���Ѿ�д�����ˣ��� !! ������ !! ��һ�Ű� !!\n" );
	target->set("message",msg);
	write("����"+(string)target->query("c_cap_name")+"�Ŀ�Ƭ��д����"+msg+"\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�������㣬��"+get_c_sex(this_player())+"������ͿͿĨĨ��\n",
		this_player() );
	
	return 1;
}

int read_msg(string arg)
{
	string msg;
	object target;
        if ( !arg || arg=="")
          return notify_fail(
			"Ҫ��ʲ���أ� Syntax : read <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("��û�����ֻ�....��\n");

	msg=target->query("message");
        if ( !msg || msg=="BLANK" )
          return notify_fail(
		(string)target->query("c_cap_name")+"��ϵ��һ�ſհ׿�Ƭ������ʲ�ᶼûд��\n" );

	write(target->query("c_cap_name")+"�Ŀ�Ƭ��д�� �� "+msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�������㣬ר�ĵĶ���"+get_c_sex(this_player())+"������\n",
                this_player() );
	return 1;
}
int smell_me(string arg)
{
	string msg,c_msg;
        object target;
        if ( !arg || arg=="")
          return notify_fail(
		"Ҫ��ʲ���أ� Syntax : smell <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("��û�����ֻ�....��\n");

        c_msg=target->query("c_smell");
	msg  =target->query("smell");
	write("������"+target->query("c_cap_name")+"�ս��Ƕˣ�"+c_msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"���������"+get_c_sex(this_player())+target->query("c_cap_name")+"��\n",
                this_player() );

	if (random(20)==10 && !bee_out)
	{
	write("ͻȻһֻ�۷�ӻ���ɳ���������ı��������һ�£��� !! ��ʹ !! ������������ !!\n" );
	this_player()->receive_damage(5);
       (CONDITION_PREFIX + "simple_poison")->apply_effect( this_player(), 5, 3 );
        tell_room( environment(this_player()), 
		"ͻȻ��һֻ�۷��"+this_player()->query("c_name")+"�Ļ���ɳ�������"+get_c_sex(this_player())+"���������һ�£�"+get_c_sex(this_player())+"���������������� !! \n",
                this_player() );
		bee_out=1;
	}
        return 1;
}
