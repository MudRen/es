#include <takeda.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("����");
	set_long( @C_LONG_DESCRIPTION
�����ڽ�����һ����ڵĵ��Σ�Ψһ��ɷ��ֵĳ��ھ����������Ĵ�����
������֮�ⶼ�ǹ⻬���ұڣ�������������ڿ�ɽ�����ɵĵ��Σ��ıڻ�Ȼ��
�ɣ�ȫ�޽ӷ졣ǽ�Ϻ�ͻأ�ĳ���һ��ֲ��(herb)��ǽ�Ƿ�����Сʯ��������
�����;��ú�����䣬����˵��˯�ˡ�
C_LONG_DESCRIPTION
	);

	set( "c_item_desc", ([ 
		"herb" : @LONG_TEXT
�������֣�Ϊ�������ֵط�����ֲ��������? ����̾������֮�Ų���࿴��
�����ۣ��ʺ��ҶƬ��ī��ɫ�İ��ƣ���Լɢ����һ�ɴ̱ǵ�ҩζ��
LONG_TEXT
, 
		"bed" : @LONG_TEXT
����С������ʯͷ�Ƴɵģ���ֵ��ǣ�����ǽ֮��û���κνӷ���ڣ����Ҳ
��ɽ��ֱ�ӵ�ɵģ���������ʯ���������ǣ��㻳����������˯�����档
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : TROOM"jail2" ]) );
	create_door( "east", "west", ([
		"keyword" : ({"door", "iron door"}),
		"name" : "iron door",
		"c_name" : "����",
		"desc" : "A strudy iron door",
		"c_desc" : "һ�Ⱥ�ʵ�Ĵ�����",
		"status" : "locked",
		"lock" : "LiangShankey-1"
	]) );
	reset();
}
int clean_up() { return 0; }