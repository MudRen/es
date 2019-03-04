#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

void	create()
{
	set_name("firework", "�̻�");
	set_short( "�̻�");
	set_long( @CLONG
����һ���̻�, ��ȼ (light) ��, �㽫����\�����Ȥ��
CLONG
    );
	set("id", ({"firework"}));
	set("unit", "��" );
	set( "weight", 10 );
	set( "value", ({ 500, "silver" }) );
}

void	init()
{
	add_action("do_light","light");
}

int		do_light(string s)
{
	object ob;
	string s1,s2;
	string msg, cmsg;
	int color;
	object *usr;
	int	i, user_number;
	
	if (!s) return notify_fail( "�����ȼʲ��?\n" );
	if ( (!ob = present(s)) || (ob != this_object())) 
		return notify_fail( "����û�����ֶ���\n" );
		
	color = random (6);
	switch (color) {
		case 0  : s1= "HIR"; s2= "��"; break;
		case 1  : s1= "HIM"; s2= "�ۺ�"; break;
		case 2  : s1= "HIY"; s2= "��"; break;
		case 3  : s1= "HIG"; s2= "��"; break;
		case 4  : s1= "HIB"; s2= "��"; break;
		case 5  : s1= "HIC"; s2= "��"; break;
		default : s1= "HIR"; s2= "��";
	}
	emote( "$NS���̻����, Ȼ����ס����Ѹ�ٵض㵽һ�ߡ�\n", 
			this_player() );
	cmsg = "�飡��һ����һö������"+ s2 + "ɫ�̻�������б��俪����\n";
    			
    usr = users();
    user_number = sizeof(usr);
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( cmsg, s1, usr[i]));
    }
	remove();
	return 1;
}
