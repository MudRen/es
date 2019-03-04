#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "light_pastil", "light" );
	add_action( "want_quit","quit" );
}

void create(){

	set_name("pastil","����");
	set_short("���������");
	set_long("����һ�����������\n");
    set("value" , ({10,"silver"}) );
	set("unit","��");
}

int light_pastil(string arg)
{
	int old_str;
	old_str = (int)this_player()->query_perm_stat("str");

	set("prevent_drop",1);
//	add("c_cap_name","����ȼ�У�");
//	add("cap_name","(light)");

	if( arg != "pastil" ) return 0;
	write( 
		"��������������㣬һ����ɫ������ȽȽ����Χ����������ԣ���е���һ��������\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"������һ�����㣬һ����ɫ����Χ�����������ԡ���\n",
		this_player() );

	this_player()->set_perm_stat("str",old_str+2);
	call_out("restore",5,this_player());
	return 1;
}

void restore(object player){

	int new_str;
	new_str = (int)player->query_perm_stat("str");
	tell_object(player,
		"Χ���������Ե�������������ʧ��...\n");
	player->set_perm_stat("str",new_str-2);
	remove();
}
int want_quit(){

	int new_str;
	new_str = (int)this_player()->query_perm_stat("str");
	tell_object(this_player(), 
	        "Χ���������Ե�������������ʧ��...\n");
	this_player()->set_perm_stat("str",new_str-2);
	remove();
}