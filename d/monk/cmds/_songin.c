//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"���� �������� ���������� ���Խ�Ϣ ���ޡ��� �������� ���Զ�֮\n",

"���� ���ж�ʮ��\n"
"ƶ�ʩ�� ����ѧ���� ���������� �ö÷��� ��ֵ������ ��ɫ������\n"
"���ò����� ���費���� �нٲ����� ���������� ��ѧ������ ����������\n"
"����δѧ�� ����ƽ���� ��˵�Ƿ��� ����֪ʶ�� ����ѧ���� �滯������\n"
"�þ������� �ƽⷽ����\n",

"���� ����� ��ǳ� ������ ��ǳ� ����� ������ ����֪ʶ �õ�����\n",

"���� �˴Ӱ������� �������� ����춰� ���Ǻβ�\n",

"�ڶ���֪ ����Ϊ�� ����ƣ�� ��̰���� ������Ϊ ��������\n",

"�ڰ˾�֪ ������Ȼ �������� ������� �ռ�һ��\n"

"Ը�������������� �������� �Ͼ�����\n",

"���Ƿ綯  ���ǡ���  �����Ķ�\n",

"��������  �����徻  ���ô���  ֱ�˳ɷ�\n",

"�������տ������ ��ʶ���԰��� ����˵ʳ���� �ڵ�˵�� ��������\n",

"Ī����˵��  �㼴����  ��һĪ����  �����ľ���  �����޼ǿ�\n",

"�����ܺ����Ǵ�  ������������\n",

"һ�м�һ  һ��һ��  ��ȥ����  ��������  �˼�����\n", 

"���򼴷� ���ռ����� ǰ���Լ����� �����򼴷�\n",

"ǰ������������ �����뾳������\n",

"Ħڭ���������� �����������һ ��ס���������� ������������\n",

"���������� ���ǻ۹��� �һ�з� ��ȡ���� ���Ǽ��Գɷ��\n",

"����һ�з� �Ĳ�Ⱦ�� �������� \n",

"�ü���һ�д� �಻��һ�д� ��������\n",

"а��������  �������ճ�  а���㲻��  �徻������\n",

"�����Լ���  ������൱  ������ٵ�  ��������\n",

"��������  ���������  ����������  �������ý�\n",

"��������  ��������  ��������  ���гټ�\n",

"�������Ĵ�  ��ȥ���Ļ�  ����������  Ī��������\n",

"�����Լ�������  ���Ծ����Ƿ�  �ȱ����ǹ���  ϲ����Ϊ����\n",

"��ƽ���ͳֽ�  ��ֱ��������  ����Т����ĸ  ������������\n",

"���ǻ��� �������� ����ƹ� ���ǹ�֮�� ���ǵ�֮�� �����ж� �屾ͬһ\n",

"һ��������  �һ�д�  �С�ס�������Գ���һֱ����Ҳ\n",

"ֱ���ǵ��� ֱ���Ǿ��� ����ֱ�� �һ�з� ����ִ��\n",

"�Ĳ�ס��  ����ͨ��  ����ס��  ��Ϊ�Ը�\n",

"���Կ���  ��Ԫ����  ֪�����  ��������Ҳ\n",

"���Կ��� ���ı��� ������� ��\������ �������� �����徻\n",

"���һ���ƶ񾳽�  �����  ��Ϊ�� �ڼ����Բ��� ��Ϊ��\n",

"������Ϊ��  �ڲ���Ϊ��  ��������  ���ļ���\n",

"���� ����ǰ� ���� ������� ǰ���� ������� �������\n",

"��������� ����� ����� ����� <--> �����  �����  ���ɮ\n"
"�����  а�Բ���  ����֪��  �����ɫ  ��������\n"
"����� ������а�� ����а���� �������ҹ���̰��ִ�� ��������\n"
"����� һ�г��Ͱ������� ���ԽӲ�Ⱦ�� ��������\n",

"�򷨴�������  ˼��һ�ж���  ��������  ˼��һ������  ��������\n",

"һ���ܳ�ǧ�갵  һ�����������\n",

"Ī˼��ǰ  �ѹ����ɵ�  ��˼���  ����Բ��  �Լ�����\n",

"������һ���  ���������  ������һ����  �á���ɳ��\n",

"������������ �������� ����������� 춿���� �������ⲻ�� һ���Ŀ�\n",

"�����޳�  ������  ��������  ����Ϊ��\n",

"�������  �����ռ�  Ӧ���ް�  ��������  ��ʥ����  ��������\n", });

void do_songin(object player, int skill, int degree )
{
	string text;
	string *colors = ({ "HIC", "HIY", "HIB" });
	
	tell_object( player,"����Ի: ");
	if( degree < 14 && skill > random(degree*degree*2) 
		&& (int)player->query("hit_points") > 10 ) {
		text = c_illusion[degree*3+random(3)];
		message("illusion", 
			set_color(text, colors[random(3)], player),player) ;

		tell_room( environment(player), 
			sprintf("%s������: %s",player->query("c_name"),
			set_color(text, colors[random(3)], player)) , player);

		player->receive_damage(random(2));
        if( (int)player->query("alignment") < 10000 )
        	player->add("alignment", degree*3);
 		call_out( "do_songin", 4, player, skill, degree + 1 );
	} else {
		player->delete_temp("block_command");
		tell_object( player, 
			"......\nһ����紵����Ĺ�ͷ����������˼����\n" );
		tell_object( player,
			"����������֮������������ŵ����磬��ֹͣ��ˡ�\n");
        tell_room( environment(player), 
		sprintf("%s���Ϸ𾭣���ƽ���ϵ�վ��������\n",player->query("c_name")), player );
	    call_out("quit_songin", degree*10, player);
	}
}

void quit_songin( object player )
{
	if( !player ) return;
	tell_object( player,
		"������������ͨ�ո������ķ𾭣����ܼ����������ˡ�\n");
	player->delete_temp("monk_songin");
}

int cmd_songin()
{
	int skill, hp, alignment;
	object me;
	
	me = this_player();
	skill = (int)me->query_skill("recitation");
	if( !skill ) return notify_fail("��û��ѧ���о����㿴��������....��\n");

         if (me->query_temp("exercising"))
              return notify_fail("�������˹����޷��о�...��\n");
	if( me->query_temp( "monk_songin" ) )
		return notify_fail("����Ҫһ��ʱ����⣬�������㹻��������..��\n");

	write("�㷭������ķ𾭣���ʼ��ϸ������������������������ׯ�ϵľ��硣\n");
		
	tell_room( environment(me), 
  		me->query("c_name")+"������������ķ𾭣����ȶ�������ʼ���̷�...��\n",
		me );

	me->set_temp("monk_songin", 1);
    if( !wizardp( me ) )
		me->set_temp("block_command", 1 );
	
	call_out( "do_songin", 4, me, skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
Syntax:  songin

This command is to sit down and reading. When you are songining, alignment
points will recovery . How long you can songin dependson your somgin skill.
Once you are awake from songin, you'll have have some headache. But that's 
normal.
HELP
	);
    return 1;
}
