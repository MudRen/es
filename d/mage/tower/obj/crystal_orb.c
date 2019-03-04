#include <mudlib.h>

inherit OBJECT;
#include "/d/mage/tower/detect-magic.h"
#define USE_SP 20
int do_use(string str);

void create()
{
		//seteuid( getuid() );
	    set_name( "crystal orb", "ˮ����" );
        add( "id", ({ "orb"}) );
        set_short( "ˮ����" );
//        set_long(@LONG
//			����һ��ˮ���򣬹�����������ڣ���ɢ����ʵĹ�â��ʹ�㲻����ʹ��(use) ������
//			LONG );
	set_long(@LONG
����һ��ˮ���򣬹�����������ڣ���ɢ����ʵĹ�â��ʹ�㲻����ʹ��(use) ������
LONG);
        set("unit","��");
        set("weight", 20);
        set( "value", ({ 20, "silver" }) );
        set("no_sale",1);

}

void init()
{
        add_action( "do_use", "use" );
}

int help ()
{
return notify_fail( "ָ���ʽ: use orb to identify �����ߡ� \n");
}

int do_use(string str)
{
	int num;
	string this1,class1;
	object dest;
	if (!str) return help();
	class1 = (string)this_player()->query("class");
	if(!( wizardp(this_player()) || class1=="mage" || class1=="necromancer" ||
		class1=="sage")) {
		write("�㲻��ħ��ʦ����֪�����ʹ�����ˮ����\n");
    		return 1;
	}	
	if (this_player()->query("spell_points") < USE_SP){
		write ("��ķ���������\n");
		return 1;
	}
	if (!this_player()->query("vision")) {
		write("��ʲ��Ҳ��������\n");
		return 1;
	}
	if (sscanf(str, "orb to identify %s", this1) == 1){
		if ( !dest= present( this1, this_player() ) )
			return notify_fail( "��û������������\n");
		num=this_player()->query_skill("identify");
		this_player()->add("spell_points", -USE_SP );
	write("�����÷���ʹ��ˮ����ˮ���򷢳���һ�������Ĺ�â��\n");
	tell_room(environment(this_player()),this_player()->query("c_name")+"���ϵ�ˮ���򷢳���һ�������Ĺ�â��\n",this_player());
		write(identify_armor(dest,num));
		return 1;
	}
	return help();
}

