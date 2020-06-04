/*
 * mk demuxer
 * Copyright (c) 2016 Paul B Mahol
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "avformat.h"
 
static int mk_write_header(AVFormatContext *s)
{
    const char *header = "hello123";
    avio_write(s->pb, header, strlen(header));
    return 0;
}
 
static int mk_write_packet(AVFormatContext *s, AVPacket *pkt)
{
    avio_write(s->pb, pkt->data, pkt->size);
    return 0;
}
 
static int mk_write_end(AVFormatContext *s)
{
    const char *trailer = "bye456";
    avio_write(s->pb, trailer, strlen(trailer));
    return 0;
}

AVOutputFormat ff_mk_muxer = {
    .name           = "mpegts",
    .long_name      = NULL_IF_CONFIG_SMALL("mk (MK Video Container)"),
    .mime_type      = "mkvideo/x-msvideo",
    .extensions     = "mk",
    .priv_data_size = 0,
    .audio_codec    = AV_CODEC_ID_NONE,
    .video_codec    = AV_CODEC_ID_RAWVIDEO,
    //.init           = mpegts_init,
    .write_header   = mk_write_header,
    .write_packet   = mk_write_packet,
    .write_trailer  = mk_write_end,
    //.deinit         = mpegts_deinit,
    //.check_bitstream = mpegts_check_bitstream,
    .flags          = AVFMT_NOTIMESTAMPS,
    //.priv_class     = &mpegts_muxer_class,
};
