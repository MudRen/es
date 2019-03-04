// org.h
// The defined variables for organization .

#define GUILD_PREFIX           "/d/"

#define LOW_ORG_EXP             1000000  //������֯����С����
#define LOW_ORG_QUEST		260	//������֯�������������
#define LEVEL_UP_QUEST		30	//ÿ��һ��������������
#define LOW_ORG_EXPLORE		600	//������֯������ƽ��ð�ն�=60%
#define LEVEL_UP_EXPLORE	50	//ÿ��һ�������ð�ն�=5%
#define LEVEL_UP_SKILL		10	//ÿ��һ����ѵ����skills�ȼ�
#define MAX_ORG_LEVEL		10	//��֯�����ȼ�

#define CLASS_NAMES ({ "adventurer","knight","mage","healer",\
        "monk", "scholar", "thief",})
#define GUILD_FILES ({ "/d/adventurer/adventurer", "/d/knight/knight",\
        "/d/mage/mage", "/d/healer/healer", "/d/monk/monk", "/d/scholar/scholar",\
        "/d/thief/thief",})

#define GUILD_DIR(x)           (GUILD_PREFIX + (x))
#define GUILD_MASTER(x)        (GUILD_PREFIX + (x) +"/" + (x))

// The defined variables for social guilds.
#define MAX_SOCIAL_GUILDS      4

#define SOCIAL_GUILD_PREFIX    "/d/std/social_guilds/"

#define SOCIAL_GUILD_MASTER(x) (SOCIAL_GUILD_PREFIX + (x))
