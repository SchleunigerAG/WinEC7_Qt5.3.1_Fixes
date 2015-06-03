/*
 * This file is part of the WebKit open source project.
 * This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "WebDOMTestException.h"

#include "KURL.h"
#include "TestException.h"
#include "WebDOMString.h"
#include "WebExceptionHandler.h"
#include <wtf/GetPtr.h>
#include <wtf/RefPtr.h>
#include <wtf/text/AtomicString.h>

struct WebDOMTestException::WebDOMTestExceptionPrivate {
    WebDOMTestExceptionPrivate(WebCore::TestException* object = 0)
        : impl(object)
    {
    }

    RefPtr<WebCore::TestException> impl;
};

WebDOMTestException::WebDOMTestException()
    : WebDOMObject()
    , m_impl(0)
{
}

WebDOMTestException::WebDOMTestException(WebCore::TestException* impl)
    : WebDOMObject()
    , m_impl(new WebDOMTestExceptionPrivate(impl))
{
}

WebDOMTestException::WebDOMTestException(const WebDOMTestException& copy)
    : WebDOMObject()
{
    m_impl = copy.impl() ? new WebDOMTestExceptionPrivate(copy.impl()) : 0;
}

WebDOMTestException& WebDOMTestException::operator=(const WebDOMTestException& copy)
{
    delete m_impl;
    m_impl = copy.impl() ? new WebDOMTestExceptionPrivate(copy.impl()) : 0;
    return *this;
}

WebCore::TestException* WebDOMTestException::impl() const
{
    return m_impl ? WTF::getPtr(m_impl->impl) : 0;
}

WebDOMTestException::~WebDOMTestException()
{
    delete m_impl;
    m_impl = 0;
}

WebDOMString WebDOMTestException::name() const
{
    if (!impl())
        return WebDOMString();

    return static_cast<const WTF::String&>(impl()->name());
}

WebCore::TestException* toWebCore(const WebDOMTestException& wrapper)
{
    return wrapper.impl();
}

WebDOMTestException toWebKit(WebCore::TestException* value)
{
    return WebDOMTestException(value);
}
