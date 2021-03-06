//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"佛言 恶人闻善 故来扰乱者 汝自禁息 当无□责 彼来恶者 而自恶之\n",

"佛言 人有二十难\n"
"贫穷布施难 豪贵学道难 弃命必死难 得睹佛经难 生值佛世难 忍色忍欲难\n"
"见好不求难 被辱不□难 有劫不临难 触事无心难 广学博究难 除灭我慢难\n"
"不轻未学难 心行平等难 不说是非难 会善知识难 见性学道难 随化度人难\n"
"睹境不动难 善解方便难\n",

"佛言 观天地 念非常 观世界 念非常 观灵觉 即菩提 如是知识 得道疾矣\n",

"佛言 人从爱欲生忧 从忧生怖 若离於爱 何忧何怖\n",

"第二觉知 多欲为苦 生死疲劳 从贪欲起 少欲无为 身心自在\n",

"第八觉知 生死炽然 苦恼无量 发大乘心 普济一切\n"

"愿代众生受无量苦 令诸众生 毕竟大乐\n",

"不是风动  不是□动  仁者心动\n",

"菩提自性  本来清净  但用此心  直了成佛\n",

"世人终日口念般若 不识自性般若 犹如说食不饱 口但说空 终无有益\n",

"莫闻吾说空  便即著空  第一莫著空  若空心静坐  便著无记空\n",

"自性能含万法是大  万法在诸人性中\n",

"一切即一  一即一切  来去自由  心体无滞  此即般若\n", 

"凡夫即佛 烦恼即菩提 前念迷即凡夫 後念悟即佛\n",

"前念著境即烦恼 後念离境即菩提\n",

"摩诃般若波罗蜜 最尊最上最第一 无住无往亦无来 三世诸佛从中生\n",

"用真如自性 以智慧观照 於一切法 不取不舍 即是见性成佛道\n",

"若见一切法 心不染著 是明无念 \n",

"用即遍一切处 亦不著一切处 但净本心\n",

"邪来烦恼至  正来烦恼除  邪正俱不用  清净至无馀\n",

"常见自己过  与道即相当  离道别觅道  终身不见道\n",

"佛法在世间  不离世间觉  离世觅菩提  犹如求兔角\n",

"人有两种  法无两般  迷悟有殊  见有迟疾\n",

"性在身心存  性去身心坏  佛向性中作  莫向性外求\n",

"自性迷即是众生  自性觉即是佛  慈悲即是观音  喜舍名为势至\n",

"心平何劳持戒  行直何用修禅  恩则孝养父母  义则上下相怜\n",

"定是慧体 慧世定用 犹如灯光 灯是光之体 光是灯之用 名虽有二 体本同一\n",

"一行三昧者  於一切处  行、住、坐、卧常行一直心是也\n",

"直心是道场 直心是净土 但行直心 於一切法 勿有执著\n",

"心不住法  道即通流  心若住法  名为自缚\n",

"若言看心  心元是妄  知心如幻  故无所看也\n",

"若言看净 人心本净 由妄念故 盖\覆真如 但无妄想 性自清净\n",

"外於一切善恶境界  心念不起  名为坐 内见自性不动 名为禅\n",

"外离相为禅  内不乱为定  外若著相  内心即乱\n",

"忏者 忏其前愆 悔者 悔其後过 前恶不起 後过不作 是名忏悔\n",

"无相三皈依 皈依觉 皈依正 皈依净 <--> 皈依佛  皈依法  皈依僧\n"
"皈依觉  邪迷不生  少欲知足  能离财色  名两足尊\n"
"皈依正 念念离邪见 以无邪见故 即无人我贡高贪爱执著 名离欲尊\n"
"皈依净 一切尘劳爱欲境界 自性接不染著 名众中尊\n",

"万法从自性生  思量一切恶事  即生恶行  思量一切善事  即生善行\n",

"一灯能除千年暗  一智能灭万年恶\n",

"莫思向前  已过不可得  常思於後  念念圆明  自见自性\n",

"自性起一念恶  灭万劫善因  自性起一念善  得□河沙恶尽\n",

"世人外迷著相 内迷著空 若能於相离相 於空离空 即是内外不迷 一念心开\n",

"诸行无常  是生灭法  生灭灭已  寂灭为乐\n",

"心如虚空  不著空见  应用无碍  动静无心  凡圣情忘  能所俱渺\n", });

void do_songin(object player, int skill, int degree )
{
	string text;
	string *colors = ({ "HIC", "HIY", "HIB" });
	
	tell_object( player,"经文曰: ");
	if( degree < 14 && skill > random(degree*degree*2) 
		&& (int)player->query("hit_points") > 10 ) {
		text = c_illusion[degree*3+random(3)];
		message("illusion", 
			set_color(text, colors[random(3)], player),player) ;

		tell_room( environment(player), 
			sprintf("%s喃喃念著: %s",player->query("c_name"),
			set_color(text, colors[random(3)], player)) , player);

		player->receive_damage(random(2));
        if( (int)player->query("alignment") < 10000 )
        	player->add("alignment", degree*3);
 		call_out( "do_songin", 4, player, skill, degree + 1 );
	} else {
		player->delete_temp("block_command");
		tell_object( player, 
			"......\n一阵清风吹向你的光头，打断了你的思绪。\n" );
		tell_object( player,
			"你从宁静祥和之境返回这个纷扰的世界，你停止念经了。\n");
        tell_room( environment(player), 
		sprintf("%s合上佛经，心平气合地站了起来。\n",player->query("c_name")), player );
	    call_out("quit_songin", degree*10, player);
	}
}

void quit_songin( object player )
{
	if( !player ) return;
	tell_object( player,
		"你觉得你终於想通刚刚所读的佛经，又能继续往下念了。\n");
	player->delete_temp("monk_songin");
}

int cmd_songin()
{
	int skill, hp, alignment;
	object me;
	
	me = this_player();
	skill = (int)me->query_skill("recitation");
	if( !skill ) return notify_fail("你没有学过诵经，你看不懂经书....。\n");

         if (me->query_temp("exercising"))
              return notify_fail("你正在运功，无法诵经...。\n");
	if( me->query_temp( "monk_songin" ) )
		return notify_fail("你需要一段时间理解，才能有足够能力再念..。\n");

	write("你翻开随身的佛经，开始仔细的念了起来，慢慢进入禅定庄严的境界。\n");
		
	tell_room( environment(me), 
  		me->query("c_name")+"翻开随身带著的佛经，盘腿而坐，开始念颂佛经...。\n",
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
