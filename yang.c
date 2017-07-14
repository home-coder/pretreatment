#include <stdio.h>

typedef int mode_t;

struct device {
	int no;
};

struct attribute {
	const char        *name;
	struct module     *owner;
	mode_t            mode;
};

struct device_attribute {
	struct attribute attr;
	ssize_t (*show)(struct device *dev, struct device_attribute *attr,
			char *buf);
	ssize_t (*store)(struct device *dev, struct device_attribute *attr,
			const char *buf, size_t count);
};

ssize_t yang_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	return 0;
}

ssize_t yang_store(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	return 0;
}
int main()
{
//----------------------简单预处理-----------------------------
//0. define
	{
#define HELLO hello
		printf("不想要  $HELLO\n");
	}

//1. normal
	{
#if __WIN32__
		printf("win32\n");
#elif __linux__
		printf("linux\n");
#endif
	}

//2. 自定义, #if 后为常量表达式
	{
		int a = 0;
#if a
		printf("a = %d\n", a);
#else
		printf("a = %d\n", a);
#endif
	}

//3. ifdef
	{
#define GLOBAL

#ifdef GLOBAL
	printf("GLOBAL\n");
#else
	printf("NO GLOBAL\n");
#endif
	}

//4. ifndef
	{
#define GLOBAL
#define TWOBAL

#ifdef GLOBAL
#undef GLOBAL
#endif
#ifdef GLOBAL
	printf("GLOBAL\n");
#ifdef TWOBAL
	printf("NO GLOBAL\n");
#endif
#endif
	}

//5. #error
	{
		int a = 0;
#if a
#error hello world, dont output -------
		printf("----------\n");
#else
		printf("do not go #error\n");
#endif
	}

//6. ifdef <==> #if (defined)
	{
#define TOMADE
#define TODAY

#if (defined TOMADE)
		printf("defined tomade\n");
#ifdef TODAY
		printf("defined today\n");
#elif (defined YESTODAY)
		printf("defined yestoday\n");
#endif
#endif
	}

//------------------复杂的预处理------------------------------
//7. # 将宏参数字符串化
	{
#define DEBUG(string) #string
		printf("%s\n", DEBUG(helloworld));
	}

//8. ## 连接符，将宏参数或者其他的串连接到一起
	{
#define __stringify(x...) #x
		printf("%s\n", __stringify(hello world));

#define __ATTR(_name,_mode,_show,_store) { \
	.attr = {.name = __stringify(_name), .mode = _mode }, \
	.show = _show,     \
	.store = _store,     \
	}

#define DEVICE_ATTR(_name, _mode, _show, _store) \
	struct device_attribute dev_attr_##_name = __ATTR(_name, _mode, _show, _store)
	DEVICE_ATTR(yang, 0755, yang_show, yang_store);
	}

//10.DEBUG相关的宏定义
{
#ifdef ANDROID
#include <android/log.h>
#define  LOGI(...) __android_log_print (ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGE(...) __android_log_print (ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#define DEBUGINFO
#ifdef DEBUGINFO
#define dbgprint(format,args...) ({ \
		fprintf (stderr, "[%s] <%d>-->", __func__, __LINE__); \
		fprintf(stderr, format, ##args);})
#else
#define dbgprint(format,args...)
#endif
	dbgprint("debug %s\n", "yes debug");
}
//9. 取消移植函数中的无关项
	{
#ifndef spin_lock_irqsave
#define spin_lock_irqsave(x, y)
#endif
#ifndef spin_unlock_irqrestore
#define spin_unlock_irqrestore(x, y)
#endif
		unsigned long flags, lock;
		spin_lock_irqsave(lock, flags);
		printf("spin is unseful\n");
		spin_unlock_irqrestore(lock, flags);

	}
	return 0;
}
