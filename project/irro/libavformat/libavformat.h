#ifndef LIBAVFORMAT_H_
#define LIBAVFORMAT_H_
class AVinputFormat
{
    public:
    AVinputFormat();
    ~AVinputFormat();
    const char *name;
    const char *long_name;
    int flags;
    const char *extensions;
    const struct AVcodecTag * const *codec_tag;
    const AVClass *priv_class; 
    const char *mime_type;
    int raw_codec_id;
    int priv_data_size;
    int flags_internal;
    int (*read_probe)(const AVProbeData *);
    int (*read_header)(struct AVFormatContext *);
    int (*read_packet)(struct AVFormatContext *, AVPacket *pkt);
    int (*read_close)(struct AVFormatContext *);
    int (*read_seek)(struct AVFormatContext *,int stream_index, int64_t timestamp, int flags);
    int64_t (*read_timestamp)(struct AVFormatContext *s, int stream_index,int64_t *pos, int64_t pos_limit);
    int (*read_play)(struct AVFormatContext *);
    int (*read_pause)(struct AVFormatContext *);
    int (*read_seek2)(struct AVFormatContext *s, int stream_index, int64_t min_ts, int64_t ts, int64_t max_ts, int flags);
    int (*get_device_list)(struct AVFormatContext *s, struct AVDeviceInfoList *device_list);
    private:
    protected:
}

class AVFormatContext{
    public:
    AVFormatContext();
    ~AVFormatContext();

    //用于实现FFmpeg对象的日志输出和命令行参数控制
    const AVclass *ac_class;

    //输入的封装格式
    const struct AVInputFormat *iformat;

    //输出的封装格式
    const struct AVOutputForamt *oformat;

    //保存私有数据
    void *priv_data;

    //该成员指向AVIOContext结构体，表示I/O上下文。AVIOContext结构体包含了I/O相关的参数，如读写缓存、读写回调函数等等。
    AVIOContext *pb;

    //该成员表示当前媒体文件中流的数量。
    unsigned int nb_streams;


    //该成员是一个指向AVStream指针的数组，表示媒体文件中所有的流
    AVStream **streams;
    
    //该成员表示文件名
    char *filename;

    //该成员表示文件的开始时间。没有则为0
    int64_t start_time;

    //文件的持续时间，单位为（us）
    int64_t duration;

    //文件的比特率，单位为bit/s
    int bit_rate;

    //表示数据包的大小。
    unsigned int packet_size;

    //该成员指向一个AVDictionary结构体，用于储存文件的元数据信息。元数据信息包括作者、标题、发行日期等等。
    AVDictionary *metadata;

    //该成员指向一个AVFormatContext结构体，表示该文件所在的上下文。如果该文件是流式媒体，则该成员为NULL。
    AVFormatContext *av_format_control;

    //该成员表示视频流的编解码器ID。
    AVCodecID video_codec_id;

    //该成员表示音频流的编解码器ID
    AVcodecID audio_codec_id;
    private:
    protected:
}

class AVPacket{
    public:
    AVPacket();
    ~AVPacket(); 
    AVBufferRef *buf;
    int int64_t pts;
    int64_t dts;
    uint8_t *data;
    int size;
    int stream_index;
    int flags;
    AVPacketSideData *side_data;
    int side_data_elems;
    int64_t duration;
    int64_t pos;
    void *opaque;
    AVBufferRef *opaque_ref;
    AVRational time_base;
    private:
    protected:
}

class libavformat {
    public:
    libavformat();
    ~libavformat();
    //解复用API
    int avformat_open_input(AVFormatContext **ps,const char *url,comst AVInputFormat *fmt,AVDictionary **options);
    int avformat_find_stream_info(AVFormatContext *ic,AVDictionary **options);

    //媒体流的处理
    int avformat_seek_file(AVFormatContext *s,int stream_index,int64_t min_ts,int64_t ts,int64_t max_ts,int flags);
    int av_seek_frame(AVFormatContext *s,int stream_index,int64_t timestamp,int flags);
    int av_read_frame(AVFormatContext *s,AVPacket *pkt);
    private:
    protected:
}

#endif