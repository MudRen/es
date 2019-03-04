#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

int	busy;

void	create()
{
	set_name("chain firework", "�����̻�");
	set_short( "�����̻�");
	set( "long", "@@long_desc" );
	set( "id", ({"chain", "firework"}));
	set( "unit", "��" );
	set( "weight", 20 );
	set( "value", ({ 5000, "silver" }) );
	busy = 0;
}

void	init()
{
	add_action("do_light", "light");
	add_action("write_message", "write");
}

string	long_desc()
{
	string s;

	s = @CLONG
����һ���̻�, �����ƺ�����Щ����ȼ (light) ����֪���ᷢ��ʲ����...
�̻�������п�ط�����д��, ����д��:
LONG
	;
	if (query("firework_message"))
		s = s + query("firework_message") + "\n";
	else 
		s = @CLONG1
����һ���̻�, �����ƺ�����Щ����ȼ (light) ����֪���ᷢ��ʲ����...
�̻�������п�ط�����д�֡�
CLONG1
	;
	return s;
}

int		write_message( string s )
{
	string	msg, ob_name;
	object	ob;

	if (!s)	return notify_fail( "write <Your Messages> on firework\n" );
	if (sscanf( s, "%s on %s", msg, ob_name) != 2)
		return notify_fail( "���������д����ȥ?\n" );
	if (!ob = present(ob_name) || ob != this_object() )
		return notify_fail( "�ⶫ��д��Ҳû��\n" );
	set( "firework_message", msg );
	emote( "$NS������д���̻���\n", this_player() );
	return 1;
}

int		do_light(string s)
{
	object	ob;

	if (busy) return nnotify_fail( "����̻��Ѿ�����ȼ��\n" );
	busy = 1;
	if (!s) return notify_fail( "�����ȼʲ��?\n" );
	if (!ob = present(s) || ob != this_object() )
		return notify_fail( "����û�����ֶ���\n" );
		
	emote( "$NS���̻����, Ȼ����ס����Ѹ�ٵض㵽һ�ߡ�\n", this_player() );
	tell_room( environment( this_player()), 
		"��������һ����Ȼ����, �㿴���޴�Ļ�����̻�ը�ϰ����\n");
	call_out( "firework_effect", 10, 0, this_object() );
	return 1;
}

void	firework_effect( int life, object me )
{
	string	*cmsg, tmsg, wmsg;
	string	*s1, *s2;
	int		color;
	object	*usr;
	int		i, user_number;

	color = random (6);
	s1 = ({ "HIR", "HIM", "HIY", "HIG", "HIB", "HIC" });
	s2 = ({ "��",  "�ۺ�", "��", "��",  "��",  "��" });
	
	cmsg = ({
	"����!����һ����, һö$Cɫ��С��������ձ���, �������������Ļ𻨡�\n",
	"������еĻ���������ʱ, ����һ��$Cɫ�Ļ�����Ϻøߡ��øߵ����, Ȼ��\n"
	"չ����Ϊ�����ļ����������¡�\n",
	"�ڼ���ı�����, ���Ż����ɵ���ɳ�, һ���ڱȽϵ͵�����б�ը, ����ǧ��\n"
	"��$Cɫ�𻨳������߷�ɢ������\n",
	"�ڶ��Ż���ը��, �Գ�ɢ��Ļ����γ���һ��Ư���ľջ���\n",
	"�����Ż��򴩹��ջ���Ļ���, �߸ߵ����Ϸ�ȥ, ը���Ļ��澹Ȼ�γ�������!\n"
	"����д����$W��\n"
	});
	
    if(me->query("firework_message"))
    	wmsg = me->query("firework_message");
    else wmsg = "���Ǵ���";
    usr = users();
    user_number = sizeof(usr);
    tmsg = replace_string(cmsg[life], "$C", s2[color]);
    tmsg = replace_string(tmsg, "$W", wmsg);
    
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( tmsg, s1[color], usr[i]));
    }
    
    if (++life < sizeof(cmsg)) 
    	call_out( "firework_effect", 10, life, me);
	else me->remove();
}